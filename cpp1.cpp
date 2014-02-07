#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "conio.h"

#define MENDIAN 10    //门店编号数
#define NAME 10   //名称长度
#define ADDRESS 10    //地址长度
#define LOUPAN 10    //楼盘编号数
#define YUANGONG 10    //员工编号数
#define FANGWU 10    //房屋编号数
#define KEHU 10    //客户编号数
#define TELEPHONE 10    //电话长度
#define PRICE 10    //价格范围长度
#define FANGYUAN 10    //房源编号长度
#define ACCOUNT 10    //账户长度
#define CODE 10    //密码长度
#define AREA 10    //面积长度
#define PRICE 10   //价格长度
#define YONGJIN 10    //佣金长度

struct mendianinfo    //门店信息
{
	char mendiannum[MENDIAN];    //门店编号
	char name[NAME];    //门店名称
	char address[ADDRESS];    //门店地址
	char loupannum[LOUPAN][LOUPAN];    //拥有楼盘编号
	char yuangongnum[YUANGONG][YUANGONG];    //拥有员工编号
}mendian[MENDIAN];

struct loupaninfo    //楼盘信息
{
	char loupannum[LOUPAN];    //楼盘编号
	char name[NAME];    //楼盘名称
	int fangwutotal;    //拥有房屋总数
	char fangwunum[FANGWU][FANGWU];    //拥有房屋编号
}loupan[LOUPAN];

struct fangwuinfo    //房屋信息
{
	char fangwunum[FANGWU];    //房屋编号
	char area[AREA];    //房屋面积
	char price[PRICE];    //房屋价格
	char yongjin[YONGJIN];    //房源提供佣金
	int state;    //房屋状态(1待售2已售3待租4已租)
}fangwu[FANGWU];

struct yuangonginfo    //员工信息
{
	char yuangongnum[YUANGONG];    //员工编号
	char name[NAME];    //员工姓名
}yuangong[YUANGONG];

struct kehumanage    //客户管理
{
	char kehunum[KEHU];    //客户编号
	char name[NAME];    //客户姓名
	char telephone[TELEPHONE];    //客户电话
	char area[AREA];    //客户所需房屋面积范围
	char price[PRICE];    //承受价格范围
	char yongjin[YONGJIN];    //客户提供佣金
	int state;    //客户状态(1求租2求购3出租4出售)
}kehu[KEHU];

struct salestatistics    //销售情况统计
{
	int total;    //房屋总数
	char fangwunum[FANGWU][FANGWU];    //房屋编号
}salefangwu,saledfangwu,rentfangwu,rentedfangwu;    //待售房源，已售房源，待租房源，已租房源

struct moneystatistics    //佣金收入统计
{
	float fangyuan;    //房源提供佣金
	float kehu;    //客户提供佣金
}money;    

struct kehustatistics    //客户情况统计
{
	int total;    //客户总数
	int kehunum[KEHU];    //客户序号
}letkehu,buykehu,rentkehu,salekehu;    //客户状态(1求租2求购3出租4出售)

struct accountmanage    //账户管理
{
	char account[ACCOUNT];    //账户
	char code[CODE];    //密码
}account;  

struct total    //统计
{
	int mendiantotal;    //门店总数
	int loupantotal;    //楼盘总数
	int fangwutotal;    //房屋总数
	int yuangongtotal;    //员工总数
	int kehutotal;    //客户总数
}total;


	char a[ACCOUNT],b[CODE];
	int c=0,i=0,j=0;
	char d[MENDIAN];
	char g[LOUPAN];
	char h[YUANGONG];
	char e[FANGWU];
	char f[KEHU];



void readdate()      //从文件读取数据到数组
{
	FILE *fp;
	if((fp=fopen("room.dat","rb"))==NULL)
	{
		printf("\ncannot open room.dat!!!\n");
		exit(0);
	}
		fread(mendian,sizeof(mendianinfo),MENDIAN,fp);
		fread(loupan,sizeof(loupaninfo),LOUPAN,fp);
		fread(fangwu,sizeof(fangwuinfo),FANGWU,fp);
		fread(yuangong,sizeof(yuangonginfo),YUANGONG,fp);
		fread(kehu,sizeof(kehumanage),KEHU,fp);
		fread(&salefangwu,sizeof(salestatistics),1,fp);
		fread(&saledfangwu,sizeof(salestatistics),1,fp);
		fread(&rentfangwu,sizeof(salestatistics),1,fp);
		fread(&rentedfangwu,sizeof(salestatistics),1,fp);
		fread(&money,sizeof(moneystatistics),1,fp);
		fread(&letkehu,sizeof(kehustatistics),1,fp);
		fread(&buykehu,sizeof(kehustatistics),1,fp);
		fread(&rentkehu,sizeof(kehustatistics),1,fp);
		fread(&salekehu,sizeof(kehustatistics),1,fp);
		fread(&account,sizeof(accountmanage),1,fp);
		fread(&total,sizeof(total),1,fp);
	fclose(fp);
}

void savedate()    //保存数据到文件
{
FILE *fp;
	if((fp=fopen("room.dat","wb"))==NULL)
	{
		printf("\ncannot open room.dat!!!\n");
		exit(0);
	}
		fwrite(mendian,sizeof(mendianinfo),MENDIAN,fp);
		fwrite(loupan,sizeof(loupaninfo),LOUPAN,fp);
		fwrite(fangwu,sizeof(fangwuinfo),FANGWU,fp);
		fwrite(yuangong,sizeof(yuangonginfo),YUANGONG,fp);
		fwrite(kehu,sizeof(kehumanage),KEHU,fp);
		fwrite(&salefangwu,sizeof(salestatistics),1,fp);
		fwrite(&saledfangwu,sizeof(salestatistics),1,fp);
		fwrite(&rentfangwu,sizeof(salestatistics),1,fp);
		fwrite(&rentedfangwu,sizeof(salestatistics),1,fp);
		fwrite(&money,sizeof(moneystatistics),1,fp);
		fwrite(&letkehu,sizeof(kehustatistics),1,fp);
		fwrite(&buykehu,sizeof(kehustatistics),1,fp);
		fwrite(&rentkehu,sizeof(kehustatistics),1,fp);
		fwrite(&salekehu,sizeof(kehustatistics),1,fp);
		fwrite(&account,sizeof(accountmanage),1,fp);
		fwrite(&total,sizeof(total),1,fp);
	fclose(fp);
}

void inputmendian()    //门店信息输入
{
c=total.mendiantotal;    
	do                                                        
	{
	printf("\n请输入门店编号：(输入0为退出)");
	scanf("%s",d);
	if (strcmp(d,"0")) 	strcpy(mendian[c].mendiannum,d);
	else break;
	printf("\n请输入门店名称：");
	scanf("%s",mendian[c].name);
	printf("\n请输入门店地址：");
	scanf("%s",mendian[c].address);
	i=0;
	do
	{
	printf("\n请输入拥有楼盘编号：(输入0为退出)");
	scanf("%s",g);
	if (strcmp(g,"0")) strcpy(mendian[c].loupannum[i],g);
	else break;
	i++;
	}
	while(i<LOUPAN);
	i=0;
	do
	{
	printf("\n请输入拥有员工编号：(输入0为退出)");
	scanf("%s",h);
	if (strcmp(h,"0"))	strcpy(mendian[c].yuangongnum[i],h);
	else break;
	i++;
	}
	while(i<YUANGONG);

	c++;
	}
	while(c<MENDIAN); 

total.mendiantotal=c;
}

void inputloupan()    //楼盘信息输入
{
c=total.loupantotal;  
	do                                                        
	{
	printf("\n请输入楼盘编号：(输入0为退出)");
	scanf("%s",g);
	if (strcmp(g,"0")) 	strcpy(loupan[c].loupannum,g);
	else break;
	printf("\n请输入楼盘名称：");
	scanf("%s",loupan[c].name);
	printf("\n请输入拥有房屋总数：");
	scanf("%d",&loupan[c].fangwutotal);
	i=0;
	do
	{
	printf("\n请输入拥有房屋编号：");
	scanf("%s",loupan[c].fangwunum[i]);
	i++;
	}
	while(i<loupan[c].fangwutotal);

	c++;
	}
	while(c<LOUPAN); 
total.loupantotal=c; 
}

void inputfangwu()    //房屋信息输入
{
c=total.fangwutotal;  
	do                                                        
	{
	printf("\n请输入房屋编号：(输入0为退出)");
	scanf("%s",e);
	if (strcmp(e,"0")) 	strcpy(fangwu[c].fangwunum,e);
	else break;
	printf("\n请输入房屋面积：");
	scanf("%s",fangwu[c].area);
	printf("\n请输入房屋价格：");
	scanf("%s",fangwu[c].price);
	printf("\n请输入房源提供佣金：");
	scanf("%s",fangwu[c].yongjin);
	printf("\n请输入房屋状态(1待售2已售3待租4已租)：");
	do
	{
	scanf("%d",&fangwu[c].state);
	if ((fangwu[c].state<1)||(fangwu[c].state>4)) printf("您输入的状态有误，请重输：");
	}
	while((fangwu[c].state<1)||(fangwu[c].state>4));

	c++;
	}
	while(c<FANGWU);  
total.fangwutotal=c; 	
}

void inputyuangong()    //员工信息输入
{
c=total.yuangongtotal;    
	do                                                        
	{
	printf("\n请输入员工编号：(输去0为退出)");
	scanf("%s",h);
	if (strcmp(h,"0")) 	strcpy(yuangong[c].yuangongnum,h);
	else break;
	printf("\n请输入员工姓名：");
	scanf("%s",yuangong[c].name);

	c++;
	}
	while(c<YUANGONG);    
total.yuangongtotal=c; 
}

void inputkehu()    //客户信息输入
{
c=total.kehutotal;  
	do                                                        
	{
	printf("\n请输入客户编号：(输入0为退出)");
	scanf("%s",f);
	if (strcmp(f,"0")) 	strcpy(kehu[c].kehunum,f);
	else break;
	printf("\n请输入客户姓名：");
	scanf("%s",kehu[c].name);
	printf("\n请输入客户电话：");
	scanf("%s",kehu[c].telephone);
	printf("\n请输入客户所需房屋面积范围：");
	scanf("%s",kehu[c].area);
	printf("\n请输入承受价格范围：");
	scanf("%s",kehu[c].price);
	printf("\n请输入客户提供佣金：");
	scanf("%s",kehu[c].yongjin);
	printf("\n请输入客户状态(1求租2求购3出租4出售)：");
	do
	{
	scanf("%d",&kehu[c].state);
	if ((kehu[c].state<1)||(kehu[c].state>4)) printf("您输入的状态有误，请重输：");
	}
	while((kehu[c].state<1)||(kehu[c].state>4));

	c++;
	}
	while(c<KEHU);  
total.kehutotal=c; 	
}

void kehustatistics()    //客户统计
{
		letkehu.total=0;
		buykehu.total=0;
		rentkehu.total=0;
		salekehu.total=0;
	for (c=0;c<total.kehutotal;c++)
	{
		if (kehu[c].state==1)
		{
			letkehu.kehunum[letkehu.total]=c;
			letkehu.total++;
		}
		if (kehu[c].state==2)
		{
			buykehu.kehunum[buykehu.total]=c;
			buykehu.total++;
		}
		if (kehu[c].state==3)
		{
			rentkehu.kehunum[rentkehu.total]=c;
			rentkehu.total++;
		}
		if (kehu[c].state==4)
		{
			salekehu.kehunum[salekehu.total]=c;
			salekehu.total++;
		}
	}
}

void outputsinglekehu(int k)    //输出单个客户信息
{
            int fstate;
			fstate=kehu[k].state;
			printf("\n客户编号：%s",kehu[k].kehunum);
			printf("\n客户姓名：%s",kehu[k].name);
			printf("\n客户电话：%s",kehu[k].telephone);
			printf("\n客户所需房屋面积范围：%s",kehu[k].area);
			printf("\n承受价格范围：%s",kehu[k].price);
			printf("\n客户提供佣金：%s",kehu[k].yongjin);
			if(fstate==1)
				printf("\n客户状态：求租\n");
			else if(fstate==2)
				printf("\n客户状态：求购\n");
			else if(fstate==3)
				printf("\n客户状态：出租\n");
			else if(fstate==4)
				printf("\n客户状态：出售\n");
}

void outputsingleyuangong(int k)    //输出单个员工信息
{

			printf("\n员工编号：%s",yuangong[k].yuangongnum);
			printf("\n员工姓名：%s",yuangong[k].name);
}

void outputsinglefangwu(int k)    //输出单个房屋信息
{
            int fstate;
			fstate=fangwu[k].state;
			printf("\n房屋编号：%s",fangwu[k].fangwunum);
			printf("\n房屋面积：%s",fangwu[k].area);
			printf("\n房屋价格：%s",fangwu[k].price);
			printf("\n房源提供佣金：%s",fangwu[k].yongjin);
			if(fstate==1)
				printf("\n房屋状态：待售\n");
			else if(fstate==2)
				printf("\n房屋状态：已售\n");
			else if(fstate==3)
				printf("\n房屋状态：待租\n");
			else if(fstate==4)
				printf("\n房屋状态：已租\n");
}

void outputsingleloupan(int k)    //输出单个楼盘信息
{
            int i; 
			printf("\n楼盘编号：%s",loupan[k].loupannum);
			printf("\n楼盘名称：%s",loupan[k].name);
			printf("\n拥有房屋总数：%d",loupan[k].fangwutotal);
			printf("\n拥有房屋编号：");
			for(i=0;i<loupan[k].fangwutotal;i++)
				printf("  %s",loupan[k].fangwunum[i]);
}

void outputsinglemendian(int k)    //输出单个门店信息
{
			printf("\n门店编号：%s",mendian[k].mendiannum);
			printf("\n门店名称：%s",mendian[k].name);
			printf("\n门店地址：%s",mendian[k].address);
}

void outputletkehu()    //输出求租客户信息
{
	for (i=0;i<letkehu.total;i++)
	{
		outputsinglekehu(letkehu.kehunum[i]);
	}
}

void outputbuykehu()    //输出求购客户信息
{
	for (i=0;i<buykehu.total;i++)
	{
		outputsinglekehu(buykehu.kehunum[i]);
	}
}

void outputrentkehu()    //输出出租客户信息
{
	for (i=0;i<rentkehu.total;i++)
	{
		outputsinglekehu(rentkehu.kehunum[i]);
	}
}

void outputsalekehu()    //输出出售客户信息
{
	for (i=0;i<salekehu.total;i++)
	{
		outputsinglekehu(salekehu.kehunum[i]);
	}
}

void rankrentkehu()    //排序显示出租客户
{
	int k[KEHU],l;
	for (c=0;c<rentkehu.total;c++)
	{
		k[c]=rentkehu.kehunum[c];
	}
	for (c=0;c<rentkehu.total-1;c++)
	{
		for(i=0;i<rentkehu.total-1;i++)
		{
			if  (atof(kehu[k[i]].price)>atof(kehu[k[i+1]].price))
			{
				l=k[i];
				k[i]=k[i+1];
				k[i+1]=l;
			}
		}
	}
	for (c=0;c<rentkehu.total;c++)
	{
		outputsinglekehu(k[c]);
	}
}

void ranksalekehu()    //排序显示出售客户
{
	int k[KEHU],l;
	for (c=0;c<salekehu.total;c++)
	{
		k[c]=salekehu.kehunum[c];
	}
	for (c=0;c<salekehu.total-1;c++)
	{
		for(i=0;i<salekehu.total-1;i++)
		{
			if  (atof(kehu[k[i]].price)>atof(kehu[k[i+1]].price))
			{
				l=k[i];
				k[i]=k[i+1];
				k[i+1]=l;
			}
		}
	}
	for (c=0;c<salekehu.total;c++)
	{
		outputsinglekehu(k[c]);
	}
}

void totalyongjin()    //统计佣金
{
money.fangyuan =0;
for (c=0;c<total.fangwutotal;c++ )
{
money.fangyuan+=atof(fangwu[c].yongjin );  //atof为库函数，功能为将字符串转换成浮点数 
}
money.kehu =0;
for (c=0;c<total.kehutotal;c++ )
{
money.kehu+=atof(kehu[c].yongjin );
}

}


void kehuchaxun()    //客户信息查询
{
	char kehunum[KEHU];
	do
		{
			printf("\n\n请输入所需查询的客户编号(输入0为退出):   ");
			scanf("%s",kehunum);
			for(c=0;c<KEHU;c++)
			{
				if (!(strcmp(kehu[c].kehunum,kehunum)))
				{
					outputsinglekehu(c);							
					break;
				}
			}
		}while(strcmp(kehunum,"0"));
}


void yuangongchaxun()    //员工信息查询 
{
	char yuangongnum[YUANGONG];
	do
	{
		printf("\n\n请输入所需查询的员工编号(输入0为退出):   ");
		scanf("%s",yuangongnum);
		for(c=0;c<YUANGONG;c++)
		{
			if (!(strcmp(yuangong[c].yuangongnum,yuangongnum)))
		{						
		outputsingleyuangong(c);
		break;
			}
		}
	}while(strcmp(yuangongnum,"0")); 

}


void fangwuchaxun()     //房屋信息查询
{
	char fangwunum[FANGWU];
	do
	{
		printf("\n\n请输入所需查询的房屋编号(输入0为退出):   ");
		scanf("%s",fangwunum);
		for(c=0;c<FANGWU;c++)
		{
			if (!(strcmp(fangwu[c].fangwunum,fangwunum)))
			{
				outputsinglefangwu(c);
				break;
			}
		}
	}while(strcmp(fangwunum,"0"));
}


void loupanchaxun()     //楼盘信息查询
{			   	
	char loupannum[LOUPAN];
	do
	{
		printf("\n\n请输入所需查询的楼盘编号(输入0为退出):   ");
		scanf("%s",loupannum);
		for(c=0;c<LOUPAN;c++)
		{
				if (!(strcmp(loupan[c].loupannum,loupannum)))
				{
					outputsingleloupan(c);
					break;
				}
		}
				}while(strcmp(loupannum,"0"));
}


void mendianchaxun()     //门店信息查询
{
	char mendiannum[MENDIAN];
	do
	{
		printf("\n\n请输入所需查询的门店编号(输入0为退出):   ");
		scanf("%s",mendiannum);
		for(c=0;c<MENDIAN;c++)
		{
			if (!(strcmp(mendian[c].mendiannum,mendiannum)))
			{
				outputsinglemendian(c);
				break;
			}
		}
	}while(strcmp(mendiannum,"0"));
}



void main()
{
	readdate(); 
a:
	printf("\n请输入您的帐号：");
	scanf("%s",a);
	printf("\n请输入您的密码：");
	for(i=0;i<9;i++)  
	{
		b[i]=getch();
		printf("*");
		if(b[i]==13)
			break;
	}
	b[i] = '\0'; 

	if ((!(strcmp("account",a)))&&(!(strcmp("code",b))))
	{
		printf("\n           ******************************************************\n");
		  printf("           ********                                      ********\n");
		  printf("           ********              欢迎进入                ********\n");
		  printf("           ********                                      ********\n");
		  printf("           ********       ~~~房屋租赁管理系统~~~         ********\n");
		  printf("           ********                                      ********\n");
		  printf("           ********                ^-^                   ********\n");
		  printf("           ********                                      ********\n");
		  printf("           ******************************************************\n");
		  
	}
	else
	{
		printf("\n           ******************************************************\n");
		  printf("           ********                                      ********\n");
		  printf("           ********     啊~您的用户名或者密码输错鸟~     ********\n");
		  printf("           ********                                      ********\n");
		  printf("           ********     ~~~不能进入房屋租赁管理系统~~    ********\n");
		  printf("           ********                                      ********\n");
		  printf("           ********             ~~哇哇哇~~               ********\n");
		  printf("           ********                                      ********\n");
		  printf("           ********   您即将退出系统~欢迎下次再来闯关~   ********\n");
		  printf("           ********                                      ********\n");
		  printf("           ********              ~~ ^0^ ~~               ********\n");
		  printf("           ********                                      ********\n");
		  printf("           ******************************************************\n");
		getchar();   
		printf("\n           ******************************************************\n");
		  printf("           ********                                      ********\n");
		  printf("           ********    ~系统破例再次送您一次闯关机会哦~  ********\n");
		  printf("           ********                                      ********\n");
		  printf("           ********       ~~~~~再来试试手气吧~~~~~       ********\n");
		  printf("           ********                                      ********\n");
		  printf("           ******************************************************\n");
		  goto a;
	}
	
	int func;
	do
	{
repeat:
		printf("\n           ******************************************************\n");
		  printf("           ********                                      ********\n");
		  printf("           ********         请选择您所需要的功能：       ********\n");
		  printf("           ********                                      ********\n");
		  printf("           ********               1.输入信息             ********\n");
		  printf("           ********                                      ********\n");
		  printf("           ********               2.查询信息             ********\n");
		  printf("           ********                                      ********\n");
		  printf("           ********               3.统计信息             ********\n");
		  printf("           ********                                      ********\n");
		  printf("           ********               0.退出系统             ********\n");
		  printf("           ********                                      ********\n");
		  printf("           ******************************************************\n");

		scanf("%d",&func);
		if(func==1)
		{
			inputmendian();
			inputloupan();
			inputfangwu();	
			inputyuangong();
			inputkehu();
			kehustatistics();
			
			savedate(); 
			goto repeat;
			break;
		}
		
		
		else if(func==2)
		{
			int fun2;
		printf("\n           ******************************************************\n");
		  printf("           ********                                      ********\n");
		  printf("           ********       请选择您所需要查询的信息：     ********\n");
		  printf("           ********                                      ********\n");
		  printf("           ********               1.客户信息             ********\n");
		  printf("           ********                                      ********\n");
		  printf("           ********               2.员工信息             ********\n");
		  printf("           ********                                      ********\n");
		  printf("           ********               3.房屋信息             ********\n");
		  printf("           ********                                      ********\n");
		  printf("           ********               4.楼盘信息             ********\n");
		  printf("           ********                                      ********\n");
		  printf("           ********               5.门店信息             ********\n");
		  printf("           ********                                      ********\n");
		  printf("           ********              0.退回主界面            ********\n");
		  printf("           ********                                      ********\n");
		  printf("           ******************************************************\n");
			scanf("%d",&fun2);
			switch(fun2)
			{
			case 1:
				{
					kehuchaxun();
					break;
				}
			
			case 2:
				{
					yuangongchaxun();
					break;
				}
			case 3: 
				{
					fangwuchaxun();
					break;
				}
		case 4:
			{
				loupanchaxun();
				break;
			}
		case 5:
			{
			mendianchaxun();
			break;
			}
		case 0:	break;}
}

else if(func==3)
{
	int fun3;
		printf("\n           ******************************************************\n");
		  printf("           ********                                      ********\n");
		  printf("           ********       请选择您所需要统计的信息：     ********\n");
		  printf("           ********                                      ********\n");
		  printf("           ********           1.客户数据分类统计         ********\n");
		  printf("           ********                                      ********\n");
		  printf("           ********           2.按照出租金额统计         ********\n");
		  printf("           ********                                      ********\n");
		  printf("           ********           3.按照出售价格统计         ********\n");
		  printf("           ********                                      ********\n");
		  printf("           ********           4.佣金数据情况统计         ********\n");
		  printf("           ********                                      ********\n");
		  printf("           ********           5.合计数据情况统计         ********\n");
		  printf("           ********                                      ********\n");
		  printf("           ********              0.退回主界面            ********\n");
		  printf("           ********                                      ********\n");
		  printf("           ******************************************************\n");
	scanf("%d",&fun3);
	switch(fun3)
	{
	case 1:
		{
			printf("\n求租客户数量为: %d\n",letkehu.total);
			printf("\n求购客户数量为: %d\n",buykehu.total);	
			printf("\n出租客户数量为: %d\n",rentkehu.total);
			printf("\n出售客户数量为: %d\n",salekehu.total);
			break;
		}
	case 2: {rankrentkehu();break;}
	case 3: {ranksalekehu();break;}
	case 4: 
		{
			totalyongjin();
			printf("\n房源提供佣金:%f\n",money.fangyuan);
			printf("客户提供佣金:%f\n",money.kehu);
		}
	default:break;
}
}
else if(func==0)
	{printf("\n请输入任意键退出系统！\n");
	return;}

}while(1);
printf("\n请输入任意键退出系统！\n");
getchar();
}
