 #import "C:\Program Files\Common Files\System\ado\msado15.dll" no_namespace rename ("EOF", "EndOfFile")
#include <iostream>
#include <iomanip> 
#include <string>
#include <cstdio>
#include <cstdlib>
using namespace std;
class LEADER
{
public:
	char Lid[10];
	char Lname[20];
	char sex[4];
	char birthday[20];
	char gschool[20];
public:
	LEADER(){}
	~LEADER(){}
};

class CITY
{
public:
	char CID[10];
	char Cname[20];
	char area[20];
	char townnum[20];
	char population[20];
public:
	CITY(){}
	~CITY(){}
};

class MAINPO
{
public:
	char PID[10];
	char Pname[20];
	char ingredient[20];
	char namedate[20];
public:
	MAINPO(){}
	~MAINPO(){}
};

class Monitor
{
public:
	char MID[10];
	char AQI[10];
	char Date[20];
	char Time[20];
public:
	Monitor(){}
	~Monitor(){}
};

class MONISTATION
{
public:
	char MSID[10];
	char MSname[20];
	char location[20];
	char phonenum[20];
public:
	MONISTATION(){}
	~MONISTATION(){}
};

class MONIPERSON
{
public:
	char MPid[10];
	char MPname[20];
	char sex[4];
	char phonenum[20];
public:
	MONIPERSON(){}
	~MONIPERSON(){}
};

class AGENT
{
public:
	char Aid[10];
	char Aname[20];
	char sex[5];
	char birthday[20];
	char phonenum[20];
public:
	AGENT(){}
	~AGENT(){}
};

int main()
{
	char choice;
	int flag = 1;
	LEADER lea;
	CITY cit;
	MAINPO mpo;
    Monitor mon;
    MONISTATION mst;
    MONIPERSON mpe;
	AGENT age;
	while(flag){
	cout<<"欢迎使用湖北省环境监测数据管理系统！\n";
	cout<<"您的身份是：省级管理员\n";
	cout<<"**********************主菜单*********************\n";
	cout<<"1 按城市查询环境监测信息\n";
	cout<<"2 按监测站编号查询工作人员姓名\n";
    cout<<"3 插入名为Herry的工作人员的信息\n";
	cout<<"4 按编号删除工作人员的信息\n";
	cout<<"5 按编号将工作人员电话号码更新为13812341236\n";
	cout<<"0 退出系统\n";
	cout<<"*************************************************\n";
	cout<<"请选择您要使用的功能：\n";
	cin>>choice;
		 switch(choice)
		 {
		 case '1':
			 {
				 string x,e;
				 e=("'");
	             printf("input city like wuhan\n");
	             cin>>x; 
	             string s1("select MID,Cname,Pname,MSname,AQI,DATE,TIME from Monitor,CITY,MONIPO,MONISTATION where CITY.CID=Monitor.CID and Monitor.PID = MONIPO.PID and Monitor.MSID = MONISTATION.MSID and CITY.Cname=");
                 s1= s1+e+x+e;
				 cout<<s1<<endl;
	             ::CoInitialize(NULL); // 初始化OLE/COM库环境 ，为访问ADO接口做准备
	             // 创建记录集对象
	             _RecordsetPtr m_pRecordset("ADODB.Recordset");
	             //创建connection对象
	             _ConnectionPtr m_pConnection("ADODB.Connection");	   
	             //设置连接字符串
	             _bstr_t strConnect=("driver={SQL Server};Server=(local)\\sqlexpress;DATABASE=HBEM;UID=sa;PWD=123");
	             _bstr_t bstrSQL(s1.c_str()); //查询语句，表stu_info
	             std::cout<<"creating from database..."<<endl;
	       try
		   {
		       m_pConnection->Open(strConnect,"","",adModeUnknown);
		       if(m_pConnection==NULL)
			   cerr<<"Lind data ERROR!n";
		       _variant_t vMID,vCname,vPname,vMSname,vAQI,vDATA,vTIME; //对应库中的cid,cname,city,discnt
		
		    while(1)
			{
			     // 取得表中的记录
		  	   m_pRecordset->Open(bstrSQL,m_pConnection.GetInterfacePtr(),adOpenDynamic,adLockOptimistic,adCmdText);
			   cout << "MID    Cname    Pname    MSname    AQI    DATA    TIME   \n";
			   cout<<"-------------------------------------------------------\n";
			   while (!m_pRecordset->EndOfFile)
			   {
				   vMID = m_pRecordset->GetCollect(_variant_t((long)0));
				   vCname = m_pRecordset->GetCollect("Cname");
				   vPname = m_pRecordset->GetCollect("Pname");
                   vMSname = m_pRecordset->GetCollect("MSname");
				   vAQI = m_pRecordset->GetCollect(_variant_t((long)0));
				   vDATA = m_pRecordset->GetCollect("DATA");
                   vTIME = m_pRecordset->GetCollect("TIME");
				   if (vCname.vt != VT_NULL   )
				   {
					  cout.setf(ios::left);
					  cout << setw(20) << (char*)(_bstr_t)vMID;
					  cout << setw(20) << (char*)(_bstr_t)vCname;
					  cout << setw(20) << (char*)(_bstr_t)vPname;
					  cout << setw(20) << (char*)(_bstr_t)vMSname;
                      cout << setw(20) << (char*)(_bstr_t)vAQI;
					  cout << setw(20) << (char*)(_bstr_t)vDATA;
					  cout << setw(20) << (char*)(_bstr_t)vTIME;
					  cout.unsetf(ios::left);
					  cout << endl;
				   }
				     m_pRecordset->MoveNext(); ///移到下一条记录
			   }
		      	    cout<<"-------------------------------------------------------\n";
			        m_pRecordset->Update();
			        //m_pConnection->Execute(query_cmd,NULL,1); //用Execute执行sql语句来删除
			        m_pRecordset->Close(); // 关闭记录集
			}  
		   } 
	               // 捕捉异常
	               catch(_com_error e)
				   {
		               // 显示错误信息
	                   cerr << "nERROR:" << (char*)e.Description();//抛出异常
				   }
	                   if(m_pConnection->State)
		               m_pConnection->Close();
	                   ::CoUninitialize();
					   break;
			 }
		 case '2':
			 {
			      string s2("select MPname from MONIPERSON,MONISTATION where MONIPERSON.MSID = MONISTATION.MSID and MONISTATION.MSID=");
				  string z,v;
				  v=("'");
				  printf("input the MSID\n");
				  cin>>z;
				  s2=s2+v+z+v;
				  cout<<s2<<endl;
                  ::CoInitialize(NULL); // 初始化OLE/COM库环境 ，为访问ADO接口做准备
	             // 创建记录集对象
	             _RecordsetPtr m_pRecordset("ADODB.Recordset");
	             //m_pRecordset.CreateInstance(__uuidof(Recordset));
	             //创建connection对象
	             _ConnectionPtr m_pConnection("ADODB.Connection");	   
	             //设置连接字符串
	             _bstr_t strConnect=("driver={SQL Server};Server=(local)\\sqlexpress;DATABASE=HBEM;UID=sa;PWD=123");
	             //_bstr_t strConnect= "Provider=SQLOLEDB;Database=HBEM; uid=login1; pwd=123;";


	             _bstr_t bstrSQL(s2.c_str()); //查询语句，表stu_info

	             std::cout<<"creating from database..."<<endl;
	       try
		   {
		       m_pConnection->Open(strConnect,"","",adModeUnknown);
		       if(m_pConnection==NULL)
			   cerr<<"Lind data ERROR!n";
		       _variant_t vMPname; //对应库中的cid,cname,city,discnt
		
		    while(1)
			{
			     // 取得表中的记录
		  	   m_pRecordset->Open(bstrSQL,m_pConnection.GetInterfacePtr(),adOpenDynamic,adLockOptimistic,adCmdText);
			   cout << "         MPname          \n";
			   cout<<"----------------------------------------------------------------\n";
			   while (!m_pRecordset->EndOfFile)
			   {
				   vMPname = m_pRecordset->GetCollect("MPname");
				   if (vMPname.vt != VT_NULL )
				   {
					  cout.setf(ios::left);
					  printf("         ");
					  cout << setw(10) << (char*)(_bstr_t)vMPname;
					  cout.unsetf(ios::left);
					  cout << endl;
				   }
				     m_pRecordset->MoveNext(); ///移到下一条记录
			   }
		      	    cout << "----------------------------------------------------------------\n";
			        m_pRecordset->Update();
			        //m_pConnection->Execute(query_cmd,NULL,1); //用Execute执行sql语句来删除
			        m_pRecordset->Close(); // 关闭记录集
			}  
		   } 
	               // 捕捉异常
	               catch(_com_error e)
				   {
		               // 显示错误信息
	                   cerr << "nERROR:" << (char*)e.Description();//抛出异常
				   }
	                   if(m_pConnection->State)
		               m_pConnection->Close();
	                   ::CoUninitialize();
				  break;
			 }
		 case '3':
			 {
			     ::CoInitialize(NULL); // 初始化OLE/COM库环境 ，为访问ADO接口做准备
	// 创建记录集对象
	_RecordsetPtr m_pRecordset("ADODB.Recordset");
	//m_pRecordset.CreateInstance(__uuidof(Recordset));
	//创建connection对象
	_ConnectionPtr m_pConnection("ADODB.Connection");	   
	//设置连接字符串
	//_bstr_t strConnect=("driver={SQL Server};Server=(local)\\sqlexpress;DATABASE=HBEM;UID=sa;PWD=123");
	_bstr_t strConnect= "Provider=SQLOLEDB;Database=HBEM; uid=sa; pwd=123;";

	_bstr_t bstrSQL("select * from MONIPERSON"); //查询语句，表stu_info
	char * query_cmd = "INSERT INTO MONIPERSON VALUES('mp07','Herry','m','13812341235','ms06')";
	std::cout<<"creating from database..."<<endl;
	try
	{
		m_pConnection->Open(strConnect,"","",adModeUnknown);
		if(m_pConnection==NULL)
			cerr<<"Lind data ERROR!n";
		_variant_t vMPid,vMPname,vsex,vphonenum,vMSID; //对应库中的cid,cname,city,discnt
		
			// 取得表中的记录
		m_pRecordset->Open(bstrSQL,m_pConnection.GetInterfacePtr(),adOpenDynamic,adLockOptimistic,adCmdText);
		m_pConnection->Execute(query_cmd,NULL,1); 
		m_pRecordset->Update();
		m_pRecordset->Close(); // 关闭记录集
		std::cout<<"Succeed!..."<<endl;
	}
	// 捕捉异常
	catch(_com_error e)
	{
		// 显示错误信息
	  // cerr << "nERROR:" << (char*)e.Description();//抛出异常
	}
	if(m_pConnection->State)
		m_pConnection->Close();
	::CoUninitialize();

				break;
			 }
		 case '4':
			 {
			     string s4=("delete from MONIPERSON where MPid=");
				 string i,v;
				 v="'";
				 printf("input MPid\n");
				 cin>>i;
				 s4=s4+v+i+v;
				 cout<<s4<<endl;
				 ::CoInitialize(NULL); // 初始化OLE/COM库环境 ，为访问ADO接口做准备
	             // 创建记录集对象
	             _RecordsetPtr m_pRecordset("ADODB.Recordset");
                 //m_pRecordset.CreateInstance(__uuidof(Recordset));
	             //创建connection对象
	             _ConnectionPtr m_pConnection("ADODB.Connection");	   
	             //设置连接字符串
	             _bstr_t strConnect=("driver={SQL Server};Server=(local)\\sqlexpress;DATABASE=HBEM;UID=sa;PWD=123");
	             //_bstr_t strConnect= "Provider=SQLOLEDB;Database=HBEM; uid=sa; pwd=123;";

	              _bstr_t bstrSQL("select * from MONIPERSON"); //查询语句，表stu_info
	              const char * query_cmd =s4.c_str();
	              std::cout<<"creating from database..."<<endl;
	    try
		{
		    m_pConnection->Open(strConnect,"","",adModeUnknown);
		    if(m_pConnection==NULL)
			    cerr<<"Lind data ERROR!n";
		        _variant_t vMPid,vMPname,vsex,vphonenum,vMSID; //对应库中的cid,cname,city,discnt
		
	        	m_pRecordset->Open(bstrSQL,m_pConnection.GetInterfacePtr(),adOpenDynamic,adLockOptimistic,adCmdText);

		        m_pConnection->Execute(query_cmd,NULL,1); //用Execute执行sql语句来删除
		        m_pRecordset->Update();
		        m_pRecordset->Close(); // 关闭记录集
		        std::cout<<"deleting from database succeed!!!"<<endl;
		}
	       // 捕捉异常
	     catch(_com_error e)
		 {
	     	// 显示错误信息
	        cerr << "nERROR:" << (char*)e.Description();//抛出异常
		 }
	       if(m_pConnection->State)
		       m_pConnection->Close();
	           ::CoUninitialize();
				 break;
			 }
		 case 5:
			 {
			 string s5=("update from MONIPERSON set phonenum = '13812341236' where MPid=");
				 string i2,v;
				 v="'";
				 printf("input MPid\n");
				 cin>>i2;
				 s5=s5+v+i2+v;
				 cout<<s5<<endl;
				 ::CoInitialize(NULL); // 初始化OLE/COM库环境 ，为访问ADO接口做准备
	             // 创建记录集对象
	             _RecordsetPtr m_pRecordset("ADODB.Recordset");
                 //m_pRecordset.CreateInstance(__uuidof(Recordset));
	             //创建connection对象
	             _ConnectionPtr m_pConnection("ADODB.Connection");	   
	             //设置连接字符串
	             _bstr_t strConnect=("driver={SQL Server};Server=(local)\\sqlexpress;DATABASE=HBEM;UID=sa;PWD=123");
	             //_bstr_t strConnect= "Provider=SQLOLEDB;Database=HBEM; uid=sa; pwd=123;";

	              _bstr_t bstrSQL("select * from MONIPERSON"); //查询语句，表stu_info
	              const char * query_cmd =s5.c_str();
	              std::cout<<"creating from database..."<<endl;
	    try
		{
		    m_pConnection->Open(strConnect,"","",adModeUnknown);
		    if(m_pConnection==NULL)
			    cerr<<"Lind data ERROR!n";
		        _variant_t vMPid,vMPname,vsex,vphonenum,vMSID; //对应库中的cid,cname,city,discnt
		
	        	m_pRecordset->Open(bstrSQL,m_pConnection.GetInterfacePtr(),adOpenDynamic,adLockOptimistic,adCmdText);

		        m_pConnection->Execute(query_cmd,NULL,1); //用Execute执行sql语句来删除
		        m_pRecordset->Update();
		        m_pRecordset->Close(); // 关闭记录集
		        std::cout<<"update from database succeed!!!"<<endl;
		}
	       // 捕捉异常
	     catch(_com_error e)
		 {
	     	// 显示错误信息
	        cerr << "nERROR:" << (char*)e.Description();//抛出异常
		 }
	       if(m_pConnection->State)
		       m_pConnection->Close();
	           ::CoUninitialize();
				 break;
			 }
		 case 0:
			 {
			     flag = 0;
				 cout<<"已退出！";
				 exit(0);
			 }
		 }
		 }
    return 0;
}
