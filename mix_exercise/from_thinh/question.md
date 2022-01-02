# Question 1:

[EN] Write a function that inserts an integer x into the given increasing integer array so that the array retains its ascending properties, then
return true.

If x has been contained inside the input array, return false as nothing changes.

[VN] Viết một hàm chèn một số nguyên X vào mảng số nguyên tăng dần cho trước sao cho mảng vẫn giữ tính tăng dần của nó, trá về true.

Trong trường hợp X đã có trong mảng thì trả về false vì mảng không thay đổi.

Test case:

    Input: X=6, arr= [1, 2, 3, 4, 5, 7]
    --> return true, arr = [1, 2, 3, 4, 5, 6, 7]
    Input: X = 5, arr = [2, 5, 7, 10, 11]
    --> return false, arr = [2, 5, 7, 10, 11]

Prototype:

    bool insertx (int X, int* array, int arrLength) {
    // Your code here
    }

&nbsp;

# Question 2:

[EN] Remove extra spaces: Input is a string, write a function to remove all extra space characters (" ") in that string.

    Example: "welcome   to   Gameloft  " => "welcome to Gameloft”

[VN] Viết một hàm chuẩn hóa chuỗi bằng cách xóa hết tất cả các ký tự trắng thừa trong chuỗi và kết quả trả về là một chuỗi đã được chuẩn hóa.

    Example: "welcome   to   Gameloft  " => "welcome to Gameloft”

Test cases:

    1 - "I        am     programmer" => "I am programmer"
    2 - "      Gameloft" => "Gameloft"

Prototype:

    const char* Remove ExtraSpaces (char* str)
    {
    // your code here
    }

&nbsp;

# Question 3:

[EN] Given a string contains list of numbers, reorder it with incremental "weight". The weight of it number will be sum of its digits.
In case of same weight, class them as if they were strings with alphabetical ordering.

_Note: All numbers in the input are positive and the list can be empty._

[VN] cho trước một chuỗi chứa các số nguyên, hãy sắp xếp lại chúng theo thứ tự tăng dần "trọng số" của nó.

Được biết "trọng số" của một số cho trước là tổng các chữ số của số nguyên đó.
Trong trường hợp cùng "trọng số" thì ưu tiên xếp chúng theo thứ tự alphabe.

_Lưu ý: Tất cả các số nguyên trong chuỗi đầu vào đều là số dương và có thể là chuỗi rỗng._

Prototype:

    const char* orderWeight(const std::string &str);
    // Your code here
    }

Test cases:

    1. orderWeight("56 65 74 100 99 68 86 180 90"); // => "100 180 90 56 65 74 68 86 99"
    2. orderWeight(""); // => ""
    3. orderWeight("5     6     87 283"); // => "5 6 283 87"
