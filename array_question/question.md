Vietnamese

### Bài tập mảng nâng cao [nguyenvanhieu]

Một số vấn đề có vẻ khó nhưng thực chất chúng rất đơn giản. Hôm này Admin Hiếu gặp khó khăn với bài toán truy vấn phạm vi. Anh ấy có một mảng 1 chiều cứa các giá trị nhị phân 0 và 1. Có 2 kiểu truy vấn:
0 L R: Kiểm tra số được hình thành từ L tới R là số chẵn hay lẻ. Số được hình thành từ L tới R là giá trị thập phân của các số nhị phân từ L tới R kết hợp lại.
1 X: Đổi giá trị nhị phân tại chỉ số thứ X.

# INPUT:

• Dòng đầu tiên chứa 2 số N và Q. Dòng tiếp theo chứa N số 0 hoặc 1 cách nhau bởi 1 dấu cách. Q dòng tiếp theo, mỗi dòng là 1 truy vấn.

# OUTPUT:

• Với các truy vấn có dạng 0 L R in ra giá trị thập phân được tạo thành từ L tới R là chẵn hay lẻ. Chẵn thì in ra “EVEN“, lẻ thì in ra “ODD” không kèm dấu nháy.

### Ràng buộc:

• 1<= N <= 10^6

• 0<= L <= R < N

• 1 <= Q <= 10^6

# SAMPLE:

| **INPUT** | **OUTPUT** |
| --------- | ---------- |
| 5 2       | EVEN       |

1 0 1 1 0
1 2
0 1 4

Giải thích: Truy vấn đầu tiên là 1 2, do đó ta đổi giá trị tại chỉ số mảng 2 từ 1 thành 0, khi đó mảng mới là: 1 0 0 1 0.
Truy vấn thứ 2 là 0 1 4, khi đó 01102 = 02^0 + 12^1 + 1\*2^2 = 610 là số chẵn; Do đó, đáp án là EVEN.

| **INPUT**           | **OUTPUT** |
| ------------------- | ---------- |
| 10 5                | ODD        |
| 1 0 0 1 0 0 0 0 0 1 | ODD        |
| 0 9 9               | ODD        |

0 0 6
1 0
1 4
0 3 3

### Sample OUTPUT with explanation

10 5

1 0 0 1 0 0 0 0 0 1

0 9 9

before: 1 0 0 1 0 0 0 0 0 1

binary = 1

dec = 1 is ODD

0 0 6

before: 1 0 0 1 0 0 0 0 0 1

binary = 0 0 0 1 0 0 1

dec = 73 is ODD

1 0

before: 1 0 0 1 0 0 0 0 0 1

after switch: 1 0 1 1 0 0 0 0 0 1

1 4

before: 1 0 1 1 0 0 0 0 0 1

after switch: 1 0 1 0 0 0 0 0 0 1

0 3 3

before: 1 0 1 0 0 0 0 0 0 1

binary = 0

dec = 73 is ODD

[nguyenvanhieu]: https://nguyenvanhieu.vn/mang-1-chieu-trong-c/
