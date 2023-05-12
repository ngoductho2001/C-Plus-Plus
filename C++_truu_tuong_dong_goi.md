==========================tính trừu tượng hóa============================
Tính trừu tượng hóa là quá trình chúng ta đi đơn giản hóa một đối tượng
<=> xác định các thuộc tính(property) và các phương pháp(method) để đáp 
ứng các yêu cầu cần thiết của chương trình ở thời điểm hiện tại.
<=> chọn lọc ra những tính chất và hành vi cốt lõi 1 đối tượng.
VD: ở một công ty nọ, có hai nhân viên được tuyển. một người lái xe ôm,
một người sửa ô tô. đề bài yêu cầu tìm đặc điểm của nhân viên và Tính
tiên lương của họ

- người lái xe ôm:
    + thuộc tính của người lái xe ôm gồm: họ tên, sđt, giới tính, cân nặng,
    CMND, sức khỏe, màu tóc, màu da, dân tộc...
    + hành động của ngươi lái xe ôm gồm: ăn, uống, ngủ, lái xe ôm, di chuyển
    nhận lương, mua xăng...
- người sửa chữa ô tô:
    + thuộc tính của người sửa ô tô: họ tên, sđt, giới tính, cân nặng, sức
    khỏe, màu tóc, màu dà, tình trạng hôn nhân, dân tộc...
    + hành động của người sửa ô tô gồm : ăn, uống, ngủ, sửa ô tô, di chuyển
    nhận lương, mua cờ lê...

=>> Vậy ở ví dụ này thuộc tính mà chúng ta cần quan tâm ở thời điểm hiện tại
của 2 người nhân viên này là họ tên, sđt, giới tính, cmnd. còn những thuộc tính
còn lại tại thời điểm này chưa cần thiết thì có thể bỏ qua.
    Hành vi cốt lõi cần quan tâm ở đây tính tiền lương.

==========================tính đóng gói========================================
- Tính đóng gói là một đặc trưng của lập trình hướng đối tượng, không cho phép
người dùng có thể truy xuất trực tiếp để thay đổi nội tại của lớp dữ liệu.
1. PUBLIC: Những thuộc tính được khai báo với từ khóa này sẽ có phạm vi hoạt động
bên trong hoặc bên ngoài class và trên toàn bộ chương trình.
2. PRIVATE: Những thuộc tính được khai báo với từ khóa này sẽ chỉ có phạm vi hoạt 
động bên trong class nội tại, và không được truy xuất bên ngoài class
3. PROTECTED: Những thuộc tính được khai báo với từ khóa này sẽ có phạm vi hoạt
động bên trong class nội tại và class kế thừa của nó.

* Đặc điểm của tính chất đóng gói: 
+ Tạo ra cơ chế ngăn ngừa việc gọi phương thức của lớp này tác động hay truy xuất
dữ liệu của đối tượng thuộc lớp khác.
+ Người lập trình có thể dựa vào cơ chế này để ngăn ngừa việc gán giá trị không 
hợp lệ vào  thành phần dữ liệu của mỗi đối tượng.
+ Không cho truy xuất 1 cách tùy tiện dữ liệu của lớp nội tại.

* Cơ chế getter và setter trong tính đóng gói:
- Khi phạm vi truy cập là private, không thể truy xuất được thì chúng ta sử dụng cơ chế
getter và setter để thay đổi thông tin khi nhập vào trước đó bị sai

VD: 
class hocsinh{
    private:
        string ten;
        uint8_t tuoi;
    public:
        string getter_ten(){
            return ten;// trả về dữ liệu của thuộc tính
        }
        string setter_ten(string TEN){
            ten = TEN;// thay đổi dữ liệu của thuộc tính
        }
}
Gỉa sử khi chúng ta nhập nhầm tên của học sinh thì:
    hs.setter_ten("ten chính xác");// vậy là có thể sử dụng setter để thay đổi nội dug bị sai



VD: làm rõ tính trừu tượng và tính đóng gói
class sinhvien{
    private: 
        char ten[20];
        uint8_t tuoi;
        uint8_t msv;
        uint8_t sdt;
        uint8_t mau_da;     // theo đặc điểm của phương thức trừu tượng thì thuộc tính mau_da và kieu_toc
        uint8_t kieu_toc;   // thì có thể loại bỏ đi để chọn lọc ra tính cốt lõi của đối tượng
    public:
        void nhap_thong_tin();
        void xuat_thong_tin();
}

void sinhvien::nhap_thong_tin(){
    printf("nhap thong tin sinh vien: ");
    scanf("%c %d %d %d" ,&ten ,&tuoi, &msv, &sdt);
}

void sinhvien::xuat_thong_tin(){
    printf("xuat thong tin sinh vien: ");
    printf("ten: %c , tuoi: %d, msv: %d, sđt: %d", sinhvien::ten, sinhvien::tuoi, sinhvien::msv, sinhvien::sdt);
}

int main(){
    sinhvien sv;
    sv.tuoi// theo tính chất của tính đóng gói thì do phạm vi khai báo là private nên nên đối tượng bên ngoài không được truy xuất một cách tùy tiện
    sv.xuat_thong_tin()//theo tính chất đóng gói k có thể truy xuất property tuoi trực tiếp nhưng có thể truy cập gián tiếp qua method xuat_thong_tin() do method nằm trong nội tại của class sinh viên
}
