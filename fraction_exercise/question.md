Vietnamese cuuduongthancong

Lớp phân số (đặt tên là 𝑃ℎ𝑎𝑛𝑆𝑜) được viết để cho phép tính toán trên phân số. Đoạn chương trình sau
đây được viết để chạy thử các phương thức và phép toán đã viết:

    int main()
    {
        PhanSo a(1, 3), c;
        int b = 8;
        c = a + (PhanSo)b;
        cout << "c = " << a << " + " << b << " = " << c << endl;
        cout << "++c: ";
        cout << "c = " << ++c << endl;
        cout << "a = " << a << " + " << c << endl;
        a += c;
        cout << "a = " << a << endl;
        b = a;
        cout << "b = " << b << endl;
        return 0;
    }

a) Giả sử các phép toán và phương thức của lớp 𝑃ℎ𝑎𝑛𝑆𝑜 đã được viết đủ và đúng. Bạn hãy cho biết
kết quả chạy của chương trình nói trên.

b) Đọc kỹ từng dòng của mã nguồn (các dòng 24 – 37) để cho biết lớp 𝑃ℎ𝑎𝑛𝑆𝑜 phải gồm tối thiểu
những phương thức và phép toán nào. Viết tập tin 𝑃ℎ𝑎𝑛𝑆𝑜. ℎ định nghĩa các phương thức cần
thiết, như hướng dẫn trong bảng sau (chép lại mã nguồn và viết bổ sung đầy đủ):

    #ifndef _PhanSo_h
    #define _PhanSo_h

    #include <iostream>

    using namespace std;

    class PhanSo
    {
    private:
        int tu, mau;
    public:
        PhanSo();
        // Các dòng mã cần viết thêm
        // ...
    };
    #endif

c) Viết mã của 5 phương thức trong số các phương thức đã khai báo ở câu trên

[cuuduongthancong]: https://cuuduongthancong.com/pvf/331355/lap-trinh-huong-doi-tuong/nguyen-tan-tran-minh-khang/pplthdt_dethi_2012.pdf?src=afile&action=hover
