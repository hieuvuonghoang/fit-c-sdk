# Tính năng

Thay đổi thời gian bắt đầu (Start Time) một hoạt động của file FIT.

# Cách sử dụng

```bash
change_time.exe <fit_file> <year> <month> <day> <hour> <minute> <second>
```

## Tham số

| Tên tham số | Mô tả                                    |
| ----------- | ---------------------------------------- |
| `fit_file`  | File FIT cần thay đổi thời gian bắt đầu. |
| `year`      | Năm của thời gian mới (1900 - 2100).     |
| `month`     | Tháng của thời gian mới (1 - 12).        |
| `day`       | Ngày của thời gian mới (1 - 31).         |
| `hour`      | Giờ của thời gian mới (0 - 23).          |
| `minute`    | Phút của thời gian mới (0 - 59).         |
| `second`    | Giây của thời gian mới (0 - 59).         |

## Ví dụ

```bash
change_time.exe activity.fit 2025 06 06 08 30 00
```

Thay đổi thời gian bắt đầu của `activity.fit` thành:

```text
2025-06-06 08:30:00
```
