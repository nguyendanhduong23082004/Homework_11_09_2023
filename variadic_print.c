#include <stdio.h>
#include <stdarg.h>

void Myprint(char *fomat,...);// Variadicfuntion_Print
double Adding_Numbers(int howmany,...); // Variadicfuntion tính trung bình cộng đối số

int main(void)
{
    char *a ="Bai tap"; 
    Myprint("%s ngay 11 thang %d \n",a,9);
    Myprint("Trung binh cong cac doi so truyen vao la: %f\n",Adding_Numbers(3,1,3,4));
    return 0;
}

void Myprint(char *format,...) 
{
    va_list list; // Tạo danh sách lưu đối số
    int int_val; // Khai báo con trỏ, biến
    double double_val;
    char *p;
    char *string_val;
    va_start(list,format); // bắt đầu khởi tạo và truy cập vào đối số đầu tiên
    for( p = format ; *p ; p++)
    {
        if(*p != '%') // Kiểm tra nếu giá trị của con trỏ p khác % thì in ra giá trị của con trỏ p
        {
            putchar(*p);
            continue;
        }
        switch(*++p)// Kiểm tra các kí tự đằng sau nếu:
        {
            case 'd': // %d thì in ra kiểu dữ liệu int...
                int_val = va_arg(list,int);
                printf("%d",int_val);
                break;
            case 'f':
                double_val = va_arg(list,double);
                printf("%f",double_val);
                break;
            case 's':
                for(string_val = va_arg(list,char *);*string_val;string_val++)
                    putchar(*string_val);
                break;
            default:
                putchar(*p);
                break;    
        }
    }
    va_end(list); // Kết thúc truy cập
}
double Adding_Numbers(int howmany,...) 
{
    int sum = 0;
    int i;
    double ans = 0;
    va_list intArgumentPointer; // Tạo danh sách lưu các đối số truyền vào
    va_start(intArgumentPointer,howmany); // Bắt đầu khởi tạo
    for( i =0; i < howmany; i++)
    {
        sum += va_arg(intArgumentPointer,int); // Truy cập và tính tổng các đối số nhập vào theo kiểu dữ liệu int
        va_end(intArgumentPointer); // Kết thúc truy cập
    }
    ans = (double)sum/howmany;
    return ans;
}