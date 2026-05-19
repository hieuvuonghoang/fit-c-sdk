FROM ubuntu:latest

LABEL org.opencontainers.image.authors="FIT SDK Team <#ENG-Consumer-SW-FITSDK-Team@garmin.com>"
LABEL org.opencontainers.image.vendor="Garmin International, Inc. - FIT SDK Team"
LABEL org.opencontainers.image.description="FitGen Docker image for Linux amd64 platform"

# Required for .NET JIT to work under QEMU/Rosetta emulation on Apple Silicon
ENV DOTNET_EnableWriteXorExecute=0

WORKDIR /data

COPY --chmod=0755 ./fitgen-linux-x64 /usr/local/bin/fitgen-linux-x64

ENTRYPOINT ["fitgen-linux-x64"]
