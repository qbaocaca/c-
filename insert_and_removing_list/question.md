Link: https://khmt.uit.edu.vn/wecode/truonganpn/assignment/4/13

Vietnamese

Không chỉ thuận tiện khi bổ sung phần tử, danh sách liên kết còn hiệu quả khi xóa bỏ phần tử ở đầu danh sách, cuối danh sách hoặc một vị trí đã xác định trong danh sách.

Hãy viết chương trình thực hiện các thao tác trên:

# INPUT

Input gồm nhiều dòng, mỗi dòng sẽ có cấu trúc ở một trong 7 dạng sau:

- **Dạng 0**: Dòng bắt đầu bằng con số 0, theo sau là một số nguyên dương < 1000, chương trình cần phải thêm con số này vào đầu danh sách

- **Dạng 1**: Dòng này bắt đầu bằng con số 1, theo sau là một số nguyên dương < 1000, chương trình cần phải thêm con số này vào cuối danh sách

- **Dạng 2**: Dòng này bắt đầu bằng con số 2, theo sau là 2 số nguyên a, b < 1000, chương trình cần tìm vị trí đầu tiên mà số a xuất hiện trong danh sách, sau đó thêm số b vào sau số này. 
- Nếu số a không có trong danh sách, thêm b vào đầu danh sách

- **Dạng 3**: Dòng này bắt đầu bằng con số 3, theo sau là một số nguyên dương n < 1000. Chương trình cần tìm số n đầu tiên trong danh sách và xóa số này.

- **Dạng 4**: Dòng này bắt đầu bằng con số 4, theo sau là một số nguyên dương n < 1000. Chương trình cần xóa tất cả số mang giá trị n ra khỏi danh sách.

- **Dạng 5**: Dòng này bao gồm con số 5, khi gặp dòng này, chương trình sẽ xóa số đầu tiên trong danh sách.

- **Dạng 6**: Dòng này bao gồm một con số 6. Đây là dòng cuối cùng trong input, báo hiệu input kết thúc

# OUTPUT

In danh sách thu được sau khi thực hiện tất cả các thao tác theo yêu cầu trong input. Danh sách được in trên một dòng với mỗi số cách nhau bởi khoảng trắng. 
Nếu danh sách rỗng, xuất ra chữ “blank” (không có ngoặc kép).

# SAMPLE

**INPUT** | **OUTPUT**
----------| ----------
1 7 | 7 5 8 4 4 0 1 9 7 3
3 3 | 

2 0 9

3 3

1 1

5

1 4

1 4

4 9

0 1

5

0 3

0 3

5

2 6 0

5

0 7

4 8

1 2

1 0

2 9 0

2 1 8

3 5

3 0

5

4 1

1 1

1 7

4 2

2 7 5

0 0

1 3

0 3

3 6

5

2 1 9

5

5

6

