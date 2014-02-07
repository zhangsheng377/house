#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "conio.h"

#define MENDIAN 10    //�ŵ�����
#define NAME 10   //���Ƴ���
#define ADDRESS 10    //��ַ����
#define LOUPAN 10    //¥�̱����
#define YUANGONG 10    //Ա�������
#define FANGWU 10    //���ݱ����
#define KEHU 10    //�ͻ������
#define TELEPHONE 10    //�绰����
#define PRICE 10    //�۸�Χ����
#define FANGYUAN 10    //��Դ��ų���
#define ACCOUNT 10    //�˻�����
#define CODE 10    //���볤��
#define AREA 10    //�������
#define PRICE 10   //�۸񳤶�
#define YONGJIN 10    //Ӷ�𳤶�

struct mendianinfo    //�ŵ���Ϣ
{
	char mendiannum[MENDIAN];    //�ŵ���
	char name[NAME];    //�ŵ�����
	char address[ADDRESS];    //�ŵ��ַ
	char loupannum[LOUPAN][LOUPAN];    //ӵ��¥�̱��
	char yuangongnum[YUANGONG][YUANGONG];    //ӵ��Ա�����
}mendian[MENDIAN];

struct loupaninfo    //¥����Ϣ
{
	char loupannum[LOUPAN];    //¥�̱��
	char name[NAME];    //¥������
	int fangwutotal;    //ӵ�з�������
	char fangwunum[FANGWU][FANGWU];    //ӵ�з��ݱ��
}loupan[LOUPAN];

struct fangwuinfo    //������Ϣ
{
	char fangwunum[FANGWU];    //���ݱ��
	char area[AREA];    //�������
	char price[PRICE];    //���ݼ۸�
	char yongjin[YONGJIN];    //��Դ�ṩӶ��
	int state;    //����״̬(1����2����3����4����)
}fangwu[FANGWU];

struct yuangonginfo    //Ա����Ϣ
{
	char yuangongnum[YUANGONG];    //Ա�����
	char name[NAME];    //Ա������
}yuangong[YUANGONG];

struct kehumanage    //�ͻ�����
{
	char kehunum[KEHU];    //�ͻ����
	char name[NAME];    //�ͻ�����
	char telephone[TELEPHONE];    //�ͻ��绰
	char area[AREA];    //�ͻ����跿�������Χ
	char price[PRICE];    //���ܼ۸�Χ
	char yongjin[YONGJIN];    //�ͻ��ṩӶ��
	int state;    //�ͻ�״̬(1����2��3����4����)
}kehu[KEHU];

struct salestatistics    //�������ͳ��
{
	int total;    //��������
	char fangwunum[FANGWU][FANGWU];    //���ݱ��
}salefangwu,saledfangwu,rentfangwu,rentedfangwu;    //���۷�Դ�����۷�Դ�����ⷿԴ�����ⷿԴ

struct moneystatistics    //Ӷ������ͳ��
{
	float fangyuan;    //��Դ�ṩӶ��
	float kehu;    //�ͻ��ṩӶ��
}money;    

struct kehustatistics    //�ͻ����ͳ��
{
	int total;    //�ͻ�����
	int kehunum[KEHU];    //�ͻ����
}letkehu,buykehu,rentkehu,salekehu;    //�ͻ�״̬(1����2��3����4����)

struct accountmanage    //�˻�����
{
	char account[ACCOUNT];    //�˻�
	char code[CODE];    //����
}account;  

struct total    //ͳ��
{
	int mendiantotal;    //�ŵ�����
	int loupantotal;    //¥������
	int fangwutotal;    //��������
	int yuangongtotal;    //Ա������
	int kehutotal;    //�ͻ�����
}total;


	char a[ACCOUNT],b[CODE];
	int c=0,i=0,j=0;
	char d[MENDIAN];
	char g[LOUPAN];
	char h[YUANGONG];
	char e[FANGWU];
	char f[KEHU];



void readdate()      //���ļ���ȡ���ݵ�����
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

void savedate()    //�������ݵ��ļ�
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

void inputmendian()    //�ŵ���Ϣ����
{
c=total.mendiantotal;    
	do                                                        
	{
	printf("\n�������ŵ��ţ�(����0Ϊ�˳�)");
	scanf("%s",d);
	if (strcmp(d,"0")) 	strcpy(mendian[c].mendiannum,d);
	else break;
	printf("\n�������ŵ����ƣ�");
	scanf("%s",mendian[c].name);
	printf("\n�������ŵ��ַ��");
	scanf("%s",mendian[c].address);
	i=0;
	do
	{
	printf("\n������ӵ��¥�̱�ţ�(����0Ϊ�˳�)");
	scanf("%s",g);
	if (strcmp(g,"0")) strcpy(mendian[c].loupannum[i],g);
	else break;
	i++;
	}
	while(i<LOUPAN);
	i=0;
	do
	{
	printf("\n������ӵ��Ա����ţ�(����0Ϊ�˳�)");
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

void inputloupan()    //¥����Ϣ����
{
c=total.loupantotal;  
	do                                                        
	{
	printf("\n������¥�̱�ţ�(����0Ϊ�˳�)");
	scanf("%s",g);
	if (strcmp(g,"0")) 	strcpy(loupan[c].loupannum,g);
	else break;
	printf("\n������¥�����ƣ�");
	scanf("%s",loupan[c].name);
	printf("\n������ӵ�з���������");
	scanf("%d",&loupan[c].fangwutotal);
	i=0;
	do
	{
	printf("\n������ӵ�з��ݱ�ţ�");
	scanf("%s",loupan[c].fangwunum[i]);
	i++;
	}
	while(i<loupan[c].fangwutotal);

	c++;
	}
	while(c<LOUPAN); 
total.loupantotal=c; 
}

void inputfangwu()    //������Ϣ����
{
c=total.fangwutotal;  
	do                                                        
	{
	printf("\n�����뷿�ݱ�ţ�(����0Ϊ�˳�)");
	scanf("%s",e);
	if (strcmp(e,"0")) 	strcpy(fangwu[c].fangwunum,e);
	else break;
	printf("\n�����뷿�������");
	scanf("%s",fangwu[c].area);
	printf("\n�����뷿�ݼ۸�");
	scanf("%s",fangwu[c].price);
	printf("\n�����뷿Դ�ṩӶ��");
	scanf("%s",fangwu[c].yongjin);
	printf("\n�����뷿��״̬(1����2����3����4����)��");
	do
	{
	scanf("%d",&fangwu[c].state);
	if ((fangwu[c].state<1)||(fangwu[c].state>4)) printf("�������״̬���������䣺");
	}
	while((fangwu[c].state<1)||(fangwu[c].state>4));

	c++;
	}
	while(c<FANGWU);  
total.fangwutotal=c; 	
}

void inputyuangong()    //Ա����Ϣ����
{
c=total.yuangongtotal;    
	do                                                        
	{
	printf("\n������Ա����ţ�(��ȥ0Ϊ�˳�)");
	scanf("%s",h);
	if (strcmp(h,"0")) 	strcpy(yuangong[c].yuangongnum,h);
	else break;
	printf("\n������Ա��������");
	scanf("%s",yuangong[c].name);

	c++;
	}
	while(c<YUANGONG);    
total.yuangongtotal=c; 
}

void inputkehu()    //�ͻ���Ϣ����
{
c=total.kehutotal;  
	do                                                        
	{
	printf("\n������ͻ���ţ�(����0Ϊ�˳�)");
	scanf("%s",f);
	if (strcmp(f,"0")) 	strcpy(kehu[c].kehunum,f);
	else break;
	printf("\n������ͻ�������");
	scanf("%s",kehu[c].name);
	printf("\n������ͻ��绰��");
	scanf("%s",kehu[c].telephone);
	printf("\n������ͻ����跿�������Χ��");
	scanf("%s",kehu[c].area);
	printf("\n��������ܼ۸�Χ��");
	scanf("%s",kehu[c].price);
	printf("\n������ͻ��ṩӶ��");
	scanf("%s",kehu[c].yongjin);
	printf("\n������ͻ�״̬(1����2��3����4����)��");
	do
	{
	scanf("%d",&kehu[c].state);
	if ((kehu[c].state<1)||(kehu[c].state>4)) printf("�������״̬���������䣺");
	}
	while((kehu[c].state<1)||(kehu[c].state>4));

	c++;
	}
	while(c<KEHU);  
total.kehutotal=c; 	
}

void kehustatistics()    //�ͻ�ͳ��
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

void outputsinglekehu(int k)    //��������ͻ���Ϣ
{
            int fstate;
			fstate=kehu[k].state;
			printf("\n�ͻ���ţ�%s",kehu[k].kehunum);
			printf("\n�ͻ�������%s",kehu[k].name);
			printf("\n�ͻ��绰��%s",kehu[k].telephone);
			printf("\n�ͻ����跿�������Χ��%s",kehu[k].area);
			printf("\n���ܼ۸�Χ��%s",kehu[k].price);
			printf("\n�ͻ��ṩӶ��%s",kehu[k].yongjin);
			if(fstate==1)
				printf("\n�ͻ�״̬������\n");
			else if(fstate==2)
				printf("\n�ͻ�״̬����\n");
			else if(fstate==3)
				printf("\n�ͻ�״̬������\n");
			else if(fstate==4)
				printf("\n�ͻ�״̬������\n");
}

void outputsingleyuangong(int k)    //�������Ա����Ϣ
{

			printf("\nԱ����ţ�%s",yuangong[k].yuangongnum);
			printf("\nԱ��������%s",yuangong[k].name);
}

void outputsinglefangwu(int k)    //�������������Ϣ
{
            int fstate;
			fstate=fangwu[k].state;
			printf("\n���ݱ�ţ�%s",fangwu[k].fangwunum);
			printf("\n���������%s",fangwu[k].area);
			printf("\n���ݼ۸�%s",fangwu[k].price);
			printf("\n��Դ�ṩӶ��%s",fangwu[k].yongjin);
			if(fstate==1)
				printf("\n����״̬������\n");
			else if(fstate==2)
				printf("\n����״̬������\n");
			else if(fstate==3)
				printf("\n����״̬������\n");
			else if(fstate==4)
				printf("\n����״̬������\n");
}

void outputsingleloupan(int k)    //�������¥����Ϣ
{
            int i; 
			printf("\n¥�̱�ţ�%s",loupan[k].loupannum);
			printf("\n¥�����ƣ�%s",loupan[k].name);
			printf("\nӵ�з���������%d",loupan[k].fangwutotal);
			printf("\nӵ�з��ݱ�ţ�");
			for(i=0;i<loupan[k].fangwutotal;i++)
				printf("  %s",loupan[k].fangwunum[i]);
}

void outputsinglemendian(int k)    //��������ŵ���Ϣ
{
			printf("\n�ŵ��ţ�%s",mendian[k].mendiannum);
			printf("\n�ŵ����ƣ�%s",mendian[k].name);
			printf("\n�ŵ��ַ��%s",mendian[k].address);
}

void outputletkehu()    //�������ͻ���Ϣ
{
	for (i=0;i<letkehu.total;i++)
	{
		outputsinglekehu(letkehu.kehunum[i]);
	}
}

void outputbuykehu()    //����󹺿ͻ���Ϣ
{
	for (i=0;i<buykehu.total;i++)
	{
		outputsinglekehu(buykehu.kehunum[i]);
	}
}

void outputrentkehu()    //�������ͻ���Ϣ
{
	for (i=0;i<rentkehu.total;i++)
	{
		outputsinglekehu(rentkehu.kehunum[i]);
	}
}

void outputsalekehu()    //������ۿͻ���Ϣ
{
	for (i=0;i<salekehu.total;i++)
	{
		outputsinglekehu(salekehu.kehunum[i]);
	}
}

void rankrentkehu()    //������ʾ����ͻ�
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

void ranksalekehu()    //������ʾ���ۿͻ�
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

void totalyongjin()    //ͳ��Ӷ��
{
money.fangyuan =0;
for (c=0;c<total.fangwutotal;c++ )
{
money.fangyuan+=atof(fangwu[c].yongjin );  //atofΪ�⺯��������Ϊ���ַ���ת���ɸ����� 
}
money.kehu =0;
for (c=0;c<total.kehutotal;c++ )
{
money.kehu+=atof(kehu[c].yongjin );
}

}


void kehuchaxun()    //�ͻ���Ϣ��ѯ
{
	char kehunum[KEHU];
	do
		{
			printf("\n\n�����������ѯ�Ŀͻ����(����0Ϊ�˳�):   ");
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


void yuangongchaxun()    //Ա����Ϣ��ѯ 
{
	char yuangongnum[YUANGONG];
	do
	{
		printf("\n\n�����������ѯ��Ա�����(����0Ϊ�˳�):   ");
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


void fangwuchaxun()     //������Ϣ��ѯ
{
	char fangwunum[FANGWU];
	do
	{
		printf("\n\n�����������ѯ�ķ��ݱ��(����0Ϊ�˳�):   ");
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


void loupanchaxun()     //¥����Ϣ��ѯ
{			   	
	char loupannum[LOUPAN];
	do
	{
		printf("\n\n�����������ѯ��¥�̱��(����0Ϊ�˳�):   ");
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


void mendianchaxun()     //�ŵ���Ϣ��ѯ
{
	char mendiannum[MENDIAN];
	do
	{
		printf("\n\n�����������ѯ���ŵ���(����0Ϊ�˳�):   ");
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
	printf("\n�����������ʺţ�");
	scanf("%s",a);
	printf("\n�������������룺");
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
		  printf("           ********              ��ӭ����                ********\n");
		  printf("           ********                                      ********\n");
		  printf("           ********       ~~~�������޹���ϵͳ~~~         ********\n");
		  printf("           ********                                      ********\n");
		  printf("           ********                ^-^                   ********\n");
		  printf("           ********                                      ********\n");
		  printf("           ******************************************************\n");
		  
	}
	else
	{
		printf("\n           ******************************************************\n");
		  printf("           ********                                      ********\n");
		  printf("           ********     ��~�����û����������������~     ********\n");
		  printf("           ********                                      ********\n");
		  printf("           ********     ~~~���ܽ��뷿�����޹���ϵͳ~~    ********\n");
		  printf("           ********                                      ********\n");
		  printf("           ********             ~~������~~               ********\n");
		  printf("           ********                                      ********\n");
		  printf("           ********   �������˳�ϵͳ~��ӭ�´���������~   ********\n");
		  printf("           ********                                      ********\n");
		  printf("           ********              ~~ ^0^ ~~               ********\n");
		  printf("           ********                                      ********\n");
		  printf("           ******************************************************\n");
		getchar();   
		printf("\n           ******************************************************\n");
		  printf("           ********                                      ********\n");
		  printf("           ********    ~ϵͳ�����ٴ�����һ�δ��ػ���Ŷ~  ********\n");
		  printf("           ********                                      ********\n");
		  printf("           ********       ~~~~~��������������~~~~~       ********\n");
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
		  printf("           ********         ��ѡ��������Ҫ�Ĺ��ܣ�       ********\n");
		  printf("           ********                                      ********\n");
		  printf("           ********               1.������Ϣ             ********\n");
		  printf("           ********                                      ********\n");
		  printf("           ********               2.��ѯ��Ϣ             ********\n");
		  printf("           ********                                      ********\n");
		  printf("           ********               3.ͳ����Ϣ             ********\n");
		  printf("           ********                                      ********\n");
		  printf("           ********               0.�˳�ϵͳ             ********\n");
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
		  printf("           ********       ��ѡ��������Ҫ��ѯ����Ϣ��     ********\n");
		  printf("           ********                                      ********\n");
		  printf("           ********               1.�ͻ���Ϣ             ********\n");
		  printf("           ********                                      ********\n");
		  printf("           ********               2.Ա����Ϣ             ********\n");
		  printf("           ********                                      ********\n");
		  printf("           ********               3.������Ϣ             ********\n");
		  printf("           ********                                      ********\n");
		  printf("           ********               4.¥����Ϣ             ********\n");
		  printf("           ********                                      ********\n");
		  printf("           ********               5.�ŵ���Ϣ             ********\n");
		  printf("           ********                                      ********\n");
		  printf("           ********              0.�˻�������            ********\n");
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
		  printf("           ********       ��ѡ��������Ҫͳ�Ƶ���Ϣ��     ********\n");
		  printf("           ********                                      ********\n");
		  printf("           ********           1.�ͻ����ݷ���ͳ��         ********\n");
		  printf("           ********                                      ********\n");
		  printf("           ********           2.���ճ�����ͳ��         ********\n");
		  printf("           ********                                      ********\n");
		  printf("           ********           3.���ճ��ۼ۸�ͳ��         ********\n");
		  printf("           ********                                      ********\n");
		  printf("           ********           4.Ӷ���������ͳ��         ********\n");
		  printf("           ********                                      ********\n");
		  printf("           ********           5.�ϼ��������ͳ��         ********\n");
		  printf("           ********                                      ********\n");
		  printf("           ********              0.�˻�������            ********\n");
		  printf("           ********                                      ********\n");
		  printf("           ******************************************************\n");
	scanf("%d",&fun3);
	switch(fun3)
	{
	case 1:
		{
			printf("\n����ͻ�����Ϊ: %d\n",letkehu.total);
			printf("\n�󹺿ͻ�����Ϊ: %d\n",buykehu.total);	
			printf("\n����ͻ�����Ϊ: %d\n",rentkehu.total);
			printf("\n���ۿͻ�����Ϊ: %d\n",salekehu.total);
			break;
		}
	case 2: {rankrentkehu();break;}
	case 3: {ranksalekehu();break;}
	case 4: 
		{
			totalyongjin();
			printf("\n��Դ�ṩӶ��:%f\n",money.fangyuan);
			printf("�ͻ��ṩӶ��:%f\n",money.kehu);
		}
	default:break;
}
}
else if(func==0)
	{printf("\n������������˳�ϵͳ��\n");
	return;}

}while(1);
printf("\n������������˳�ϵͳ��\n");
getchar();
}
