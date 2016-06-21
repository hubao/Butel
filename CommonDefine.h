#ifndef _COMMON_DEFINE_H_
#define  _COMMON_DEFINE_H_

#include "json.h"
#include "GMEmbedSmartPtr.h"

/////////////////////////////////

using namespace std;

enum VERMSGID
{

	VMID_QUERYVER = 1000 ,   //版本查询请求  x86-> autosrv
	VMID_QUERYVERRSP = 1001, //版本查询回应  autosrv -> x86 ,类型:强制查询响应
	VMID_OPTIMIZEVERNOTICE = 1002,	//autosrv -> x86主体  ,优化升级通知,优化升级开始执行请求
	VMID_OPTIMIZEBEGINRSP =1003,	//x86主体 -> autosrv  优化升级开始执行请求 
	VMID_FORCEBEGINREQ = 1004,		//x86主体 -> autosrv  强制升级开始执行的命令

	VMID_X86INNER_POSTQRY = 2000,	//X86 自己发起的版本查询
	VMID_X86INNER_STARTFORCE = 2001 ,//X86自己发起的开始强制版本更新
	VMID_X86INNER_STARTOPTIMATE = 2002 ,//X86自己发起的开始优化版本更新

	VMID_AUTONPSQRY		=3000,		//autosrv->autosrv 自动更新服务器内部开始nps查询，查询失败，则过一会儿再查，直到成功。
	VMID_SETX86HOSTADDR	=3001,		//autosrv->autosrv 自动更新服务器内部通知Session 目标的地址和端口。
	VMID_QRYVERRESULT = 3002 ,		//通知Session 查询结果。
	VMID_DOWNUPDATOREND = 3003,		//下载更新引导程序结果
	VMID_DOWNPKGEND		= 3004,		//下载安装包结果

	DONEXTTASKMSGID = 4000,
	DEVICELOSTMSGID = 4001,
	DONEXTRETRYMSGID = 4002,
	DONEXTTASKMSGSLEEPID = 4003,	//// 休息1秒后的尝试处理后面的任务	
	NETSESSION_SETADDR = 5000,	

};


#define VERCFGNAME		"version.config"
#define INIRELATIVEDIR	"\\config"

#define NPSPARAM1	"X1MeetingCommon"   //X1MeetingCommon
#define NPSPARAM2	"X1MeetingAppUpdate"
#define NPSPARAM3	"X86MeetingUpdate"




#define BASECONFIG "\\config"
#define BASEVOICE "\\Resources\\voice"
#define BASEZIKU "\\Resources\\ziku"

#define USERDATAROOT "\\UserData" 
#define USERDATACONTACT "\\UserData\\contacter" 
#define USERDATASETTING "\\UserData\\setting" 

#define BASEUPDATOR "\\updator"
#define BASELOG	"\\LOG"

#define UPCHIDDIR "\\updator\\"
#define PKGCHIDIR "\\pkg\\"


class NPSX1MeetingAppUpdate
{
public:
	NPSX1MeetingAppUpdate()
	{

	}
	~NPSX1MeetingAppUpdate()
	{

	}
	void operator=(const NPSX1MeetingAppUpdate & rht );
	int ParseResponseCmd ( Json::Value & jsonv,bool bx86 =false);
public:
	std::string m_ServerUrl;
	std::string m_ProjectName;
	std::string m_CheckInterval;
	std::string m_DeviceType;
	U16			m_x86boxport;
	U16			m_x86updatport;


};

class NPSResponse
{
public:
	NPSResponse(void){};
	~NPSResponse(void){};
	I32 ParseResponseCmd(const char * buffer ,U32 bufflen);

	//NPSX1MeetingCommon	m_common;
	NPSX1MeetingAppUpdate m_appup;
	NPSX1MeetingAppUpdate m_appupx86;

	std::string m_message;
	int m_status;

};


typedef GMEmbedSmartPtr<NPSResponse> SptrNPSRsp;

/////////////////////////////////////////////////////////////

class UpdateResult
{
public:
	UpdateResult(){};
	~UpdateResult(){};
	I32 ParseResponseCmd(const char * buffer ,U32 bufflen);

public:
	int		m_rccode;		//返回码 0表不需要升级，1表需要升级
	std::string	m_rcdsp;
	std::string	m_version;
	std::string	m_updaotorurl;
	std::string	m_updatorCode;
	std::string	m_installer;
	std::string	m_installerCode;
	int			m_interval;
	int			m_compatible;  // 1:兼容 0：不兼容

	std::string	m_localupatepath;
	std::string m_localpkgpath;
	int			m_downresult;	//本次下载结果

};


typedef enum _WarnType_Enum
{
	WT_VD			= 0, //vedio
	WT_AC			= 1, //auio capture
	WT_AR			= 2, //audio render
	WT_VCAP			= 3, //视频播放设备
	WT_NET			= 4, //"网络断开了,请检查网线连接情况!"
	WT_NETCONN		= 5, //网络连接
} WarnType;


struct __DeviceMiss{
	//0- 视频采集设备丢失，1-音频采集设备丢失，2-音频播放设备丢失
	//100 开始自定义的，100：网络断
	int m_error_code ;
	//char m_error_description[1024];
	//0-不需要重启，设备连接即可用。1-设备连接上需要重启才能恢复。
	int m_need_restart_graph;
	//I32		m_hintaddr;
};

inline std::string GetDeviceName(int did)
{
	switch(did)
	{
	case 0:
		return "视频采集设备";
	case 1:
		return "音频采集设备";
	case 2:
		return "音频播放设备";
	case 100:
		return "网络设备";
	default:
		{
			char tmpdes[100]={0};
			sprintf( tmpdes,"未知的设备序号:%d",did);
		}
	}
	return "未知设备号";
}




enum WAITTIMERTYPE
{
	WTT_LOADCFG		= 1 ,//获取NPS 参数类型的重试
	WIT_BINDTOKEN	=2 ,	//绑定token
	WIT_UI_TOKEN	= 3,	//启动的时候UI 调用 获取token
	WIT_UI_TOKEN_RTRY=4, //启动的时候UI 调用 获取token,失败后的重试调用阶段
	WIT_REGET_TOKEN = 5, //token  失效后的调用获取token
	WIT_REGET_TOKENRE = 6, //token  失效后的调用获取token,失败后的重试调用阶段

};

enum EPCENTERERRCODE
{
	EPEC_NOSERVICE = -439, //企业中心登陆返回,服务未开通
	EPEC_SERVICEOUT= -940, //企业中心登陆返回,服务逾期
};
#endif