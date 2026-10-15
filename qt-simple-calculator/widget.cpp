#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setFixedSize(300,250);//显示窗口大小固定
    this->setWindowTitle("Qt计算器");//设置窗口名称

    QStringList btnName = {"7","8","9","+","4","5","6","-","1","2","3","*",".","0","=","/"};

    Label = new QLabel(this);
    QFont font;
    //设置字体
    font.setFamily(QString::fromUtf8("Agency FB"));//这里的fromUtf8是string类的静态转换函数：将一段UTF-8编码的普通C风格字符串转成一个标准的QString对象
    font.setPointSize(20);//字体大小
    font.setBold(true);//字体加粗

    Label->setFont(font);//将设置好的Font应用到按钮上面
    Label->setText("0");//一开始用户什么都没有输入时默认为0
    Label->setAlignment(Qt::AlignRight);//对齐方式设置为右对齐
    Label->setGeometry(20,5,250,30);
    Label->setStyleSheet("border:1px solid red;");

    int row = 45;//行
    int col = 0;//列
    for(int i =0;i<16;++i){
        btn[i] = new QPushButton(btnName[i],this);
        btn[i]->setGeometry(col*60+30,row,50,30);
        col++;
        if((col+1)%5==0){
            row += 45;
            col = 0;
        }
        // btnMapper->setMapping(btn[i],col+1);
        connect(btn[i],&QPushButton::clicked,[=](){

            if(btnName[i]=="="){
                QJSEngine myEngine;//选中QJSEngine然后点F1可以进入帮助，去看要用这个需要在哪里配置什么,然后发现是要在CMake需要在.txt里面配置信息
                QString calStr = Label->text();//获取计算器里面计算器框里面的数字
                QJSValue calResult = myEngine.evaluate(calStr);//这个.evaluate()函数可以直接计算字符然后得到QJSValue类的结果
                if(calResult.isError()){
                    Label->setText("0");
                }//判断表达式计算结果是否有误，若有误显示0
                else{
                    Label->setText(calResult.toString());
                }//将QJSValue类转化为string类并显示在显示框内
            }

            else if(btnName[i]=="+"||btnName[i]=="-"||btnName[i]=="*"||btnName[i]=="/"){
                    QString inputStr = Label->text();
                    if(flag){
                        flag = false;
                    }//假->运算符  真->数字
                    else{
                        int inputLength = inputStr.length()-1;
                        Label->setText(inputStr.left(inputLength));//取字符串左边开始的多少位数
                    }//如果是字符后面接字符，那就把原来输入的字符给消除，然后加上新的字符
            Label->setText(Label->text()+btnName[i]);
}

                else{
                    if(Label->text()=="0")//如果括号里只有一个0，就把这个0去除。防止出现07这种情况
                    Label->setText("");
                flag = true;//设置上一个输入的是数字键}
            Label->setText(Label->text()+btnName[i]);
}
         }

   );
}

}


Widget::~Widget()
{
    delete ui;
}
