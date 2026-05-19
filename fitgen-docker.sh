#!/usr/bin/env bash
set -euo pipefail

usage() {
    cat <<EOF
Usage: $(basename "$0") [OPTIONS] [FITGEN_ARGS...]

Builds and runs FitGen inside Docker or Podman for the Linux amd64 platform.

Options:
  -h         Show this help message and FitGen help, then exit
  -verbose   Enable verbose build output

Any additional arguments are passed through to FitGen.
EOF
}

VERBOSE=false
PASSTHROUGH_ARGS=()
for arg in "$@"; do
    case "$arg" in
        -h)   usage; PASSTHROUGH_ARGS+=("$arg") ;;
        -verbose)    VERBOSE=true ;;
        *)           PASSTHROUGH_ARGS+=("$arg") ;;
    esac
done

CONTAINER_CMD=""
if command -v docker &>/dev/null && docker info &>/dev/null 2>&1; then
    CONTAINER_CMD="docker"
elif command -v podman &>/dev/null; then
    CONTAINER_CMD="podman"
elif command -v docker &>/dev/null; then
    echo "Error: Docker daemon is not running." >&2
    exit 1
else
    echo "Error: Neither Docker nor Podman is installed or in PATH." >&2
    exit 1
fi

REPO_ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

REQUIRED_FILES=(
    "$REPO_ROOT/Dockerfile"
    "$REPO_ROOT/fitgen-linux-x64"
)

for file in "${REQUIRED_FILES[@]}"; do
    if [[ ! -f "$file" ]]; then
        echo "Error: Required file not found: $file" >&2
        exit 1
    fi
done

BUILD_ARGS=(--platform linux/amd64 -f "$REPO_ROOT/Dockerfile" -t fitgen "$REPO_ROOT")
if [[ "$VERBOSE" == true ]]; then
    "$CONTAINER_CMD" build "${BUILD_ARGS[@]}"
else
    "$CONTAINER_CMD" build "${BUILD_ARGS[@]}" -q >/dev/null
fi

"$CONTAINER_CMD" run --rm -it --platform linux/amd64 \
    -v "$(pwd):/data" \
    fitgen "${PASSTHROUGH_ARGS[@]+"${PASSTHROUGH_ARGS[@]}"}"
