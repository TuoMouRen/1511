

1)
If s is a pointer to a struct s->field is equivalent to (*s).field





2)
通过结构体指针可以获取结构体成员，一般形式为：
    (*pointer).memberName
或者：
    pointer->memberName
第一种写法中，"."的优先级高于"*"，"(*pointer)"两边的括号不能少。如果去掉括号写作"*pointer.memberName"，那么就等效于"*(pointer.numberName)"，这样意义就完全不对了。

第二种写法中，"->"是一个新的运算符，习惯称它为“箭头”，有了它，可以通过结构体指针直接取得结构体成员；这也是"->"在C语言中的唯一用途。

上面的两种写法是等效的，我们通常采用后面的写法，这样更加直观。





3)
example1:

    struct name stu1;//define a new struct variable called stu1;
    stu1.membername = "123";//give value to "membername" in struct variable "stu1",

example2:

    struct name *pointer = &stu1;//define a pointer point to "stu1";
    pointer->membername = "123";

example3:

    typedef struct name STU;//struct name == STU;
    STU stu1;//example1
    STU *pointer = &stu1;//example2

example4:

    struct stu{
        char *name;  //姓名
        int num;  //学号
        int age;  //年龄
        char group;  //所在小组
        float score;  //成绩
    } stu1 = { "Tom", 12, 18, 'A', 136.5 }, *pstu = &stu1;
    //the same as the 
    struct stu{
        char *name;  //姓名
        int num;  //学号
        int age;  //年龄
        char group;  //所在小组
        float score;  //成绩
    } stu1 = { "Tom", 12, 18, 'A', 136.5 };
    //结构体指针
    struct stu *pstu = &stu1;




