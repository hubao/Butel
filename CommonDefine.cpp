#include "stdafx.h"
#include "CommonDefine.h"
#include "assert.h"
#include "pubfunction.h"
#include "LogPub.h"


//int NPSX1MeetingCommon::ParseResponseCmd(Json::Value & jsonv)
//{
//	Json::Value comminfo = jsonv[ NPSPARAM1 ]	;//jsonv["X1MeetingCommon"]	;
//	if( comminfo.empty() )
//	{
//		Log::writeError(  N8_AGENT_LOGTYPE , N8_AGENT_LOGSUBID,
//			"[AUTO] [NPS] 无法解析结果 NPSX1MeetingCommon 数据[X1MeetingCommon]"  );
//		return -3;
//	}
//	if( comminfo.empty() || ! comminfo.isString() )
//	{
//		Log::writeError(  N8_AGENT_LOGTYPE , N8_AGENT_LOGSUBID,
//			"[AUTO] [NPS] 无法解析结果 %s " ,NPSPARAM1 );
//		return -5;
//	}
//	Json::Value rcurlinfo ;
//
//	if( comminfo.type() == Json::objectValue )
//	{
//		rcurlinfo = comminfo["RC_URL"]	;
//	}
//	else if ( comminfo.type() == Json::stringValue )
//	{
//		std::string commcontent = comminfo.asString();
//		char * outbuf = NULL;
//		outbuf = strrep( const_cast<char*>( commcontent.c_str() ) , "\\r\\n",""  ) ;
//		if( outbuf )
//		{
//			printf("repla result:%s \r\n",outbuf);
//
//			char * outbuf2 = strrep (outbuf,"\\\"","\"");
//			if( outbuf2 )
//			{
//				Json ::Reader freader;  
//				Json::Value root;
//				if(!freader.parse(outbuf2,root ) )
//				{		
//					Log::writeError( N8_AGENT_LOGTYPE , N8_AGENT_LOGSUBID,
//						"[AUTO] [NPS] 无法解析 NPS 内部结果json数据，:%s", outbuf2  );
//					return -6;		
//				}
//				rcurlinfo = root["RC_URL"]	;				
//
//				printf("relpal 2 :%s \r\n",outbuf2 );
//				free ( outbuf2 );
//			}
//			free( outbuf );
//		}
//		else
//		{
//			printf("repl failed \r\n");
//
//		}
//	}
//
//
//	if( rcurlinfo.empty() )
//	{
//		Log::writeError(  N8_AGENT_LOGTYPE , N8_AGENT_LOGSUBID,
//			"[AUTO] [NPS] 无法解析结果 NPSX1MeetingCommon 数据[RC_URL]  ");
//		return -4;
//	}
//	std::string urldata = rcurlinfo.asString();
//
//	char tmpbuf[100]={0};
//	strcpy(tmpbuf,urldata.c_str() );
//	char * thesep = strchr (tmpbuf,'|');
//	if( thesep )
//		*thesep = 0;
//	int iret = SeparateColonStr(tmpbuf , m_rcurl_ip1 ,m_rcurl_pt1);
//	if(iret != 0 )
//	{
//		Log::writeError(  N8_AGENT_LOGTYPE , N8_AGENT_LOGSUBID,
//			"[AUTO] [NPS] 无法解析结果 NPSX1MeetingCommon 数据[RC_URL ip1 pt1]  ");
//		return iret;
//	}
//	memset(tmpbuf,0,sizeof(tmpbuf));
//	strcpy(tmpbuf,urldata.c_str() );
//	thesep = strchr (tmpbuf,'|');
//	if( thesep )
//	{
//		char tmpbuf2[100]={0};
//		strcpy(tmpbuf2,thesep+1);
//		iret = SeparateColonStr(tmpbuf2 , m_rcurl_ip2 ,m_rcurl_pt2);
//		if(iret != 0 )
//		{
//			Log::writeError(  N8_AGENT_LOGTYPE , N8_AGENT_LOGSUBID,
//				"[AUTO] [NPS] 无法解析结果 NPSX1MeetingCommon 数据[RC_URL ip2 pt2]  ");
//			return iret;
//		}
//	}
//	return 0;
//}
//void NPSX1MeetingCommon::operator=(const NPSX1MeetingCommon & rht )
//{
//	strcpy(m_rcurl_ip1,rht.m_rcurl_ip1);
//	m_rcurl_pt1 = rht.m_rcurl_pt1 ;
//	strcpy(m_rcurl_ip2 , rht.m_rcurl_ip2 );	
//	m_rcurl_pt2 = rht.m_rcurl_pt2;
//}
//////////////////////////

void NPSX1MeetingAppUpdate::operator=(const NPSX1MeetingAppUpdate & rht )
{
	m_ServerUrl = rht.m_ServerUrl;
	m_ProjectName = rht.m_ProjectName;
	m_CheckInterval = rht.m_CheckInterval;
	m_DeviceType = rht.m_DeviceType;	
}
int NPSX1MeetingAppUpdate::ParseResponseCmd ( Json::Value & jsonv,bool bx86)
{
	Json::Value t_ServerUrl;;
	Json::Value t_ProjectName;
	Json::Value t_CheckInterval;
	Json::Value t_DeviceType;


	Json::Value t_x86boxport;
	Json::Value t_x86updport;


	Json::Value appupdateinfo ;
	if( bx86 )
	{
		appupdateinfo = jsonv[ NPSPARAM3 ]	;//jsonv["X1MeetingAppUpdate"]	;
	}
	else
	{
		appupdateinfo = jsonv[ NPSPARAM2 ]	;//jsonv["X1MeetingAppUpdate"]	;
	}

	if( appupdateinfo.empty() )
	{
		Log::writeError(  N8_AGENT_LOGTYPE , N8_AGENT_LOGSUBID,
			"[AUTO] [NPS] 无法解析结果 NPSX1MeetingCommon 数据[X1MeetingAppUpdate]"  );
		return -3;
	}
	if( appupdateinfo.empty() || ! appupdateinfo.isString() )
	{
		Log::writeError(  N8_AGENT_LOGTYPE , N8_AGENT_LOGSUBID,
			"[AUTO] [NPS] 无法解析结果 %s " ,NPSPARAM2 );
		return -5;
	}

	if( appupdateinfo.type() == Json::objectValue )
	{
		t_ServerUrl= appupdateinfo["ServerUrl"]	;
		t_ProjectName= appupdateinfo["ProjectName"]	;
		t_CheckInterval= appupdateinfo["CheckInterval"]	;
		t_DeviceType= appupdateinfo["DeviceType"]	;


	}
	else if ( appupdateinfo.type() == Json::stringValue )
	{
		std::string commcontent = appupdateinfo.asString();
		char * outbuf = NULL;
		outbuf = strrep( const_cast<char*>( commcontent.c_str() ) , "\\r\\n",""  ) ;
		if( outbuf )
		{
			//printf("repla result:%s \r\n",outbuf);

			char * outbuf2 = strrep (outbuf,"\\\"","\"");
			if( outbuf2 )
			{
				Json ::Reader freader;  
				Json::Value root;
				if(!freader.parse(outbuf2,root ) )
				{		
					Log::writeError( N8_AGENT_LOGTYPE , N8_AGENT_LOGSUBID,
						"[AUTO] [NPS] 无法解析 NPS 内部结果appupdate json数据，:%s", outbuf2  );
					return -6;		
				}
				
				t_ServerUrl= root["ServerUrl"]	;
				t_ProjectName= root["ProjectName"]	;
				t_CheckInterval= root["CheckInterval"]	;
				t_DeviceType = root["DeviceType"];
				t_x86boxport = root["x86boxport"];
				t_x86updport = root["x86updateserviceport"];
				 
				free ( outbuf2 );
			}
			free( outbuf );
		}
		else
		{
			printf("repl failed \r\n");

		}
	}


	//if( t_ServerUrl.empty() )
	//{
	//	Log::writeError(  N8_AGENT_LOGTYPE , N8_AGENT_LOGSUBID,
	//		"[AUTO] [NPS] 无法解析结果 %s 数据[ SRVURL]  ",NPSPARAM2 );
	//	return -4;
	//}
	//if( t_ProjectName.empty() )
	//{
	//	Log::writeError(  N8_AGENT_LOGTYPE , N8_AGENT_LOGSUBID,
	//		"[AUTO] [NPS] 无法解析结果 %s 数据[ projectname]  ",NPSPARAM2 );
	//	return -5;
	//}

	if( bx86 )
	{
		m_x86boxport = t_x86boxport.asUInt();
		m_x86updatport = t_x86updport.asUInt();

	}
	else
	{
		m_ServerUrl = t_ServerUrl.asString();
		m_ProjectName = t_ProjectName.asString();
		m_CheckInterval = t_CheckInterval.asString();
		m_DeviceType = t_DeviceType.asString();
	}

	return 0;
}


///////////////////////////////

I32 NPSResponse::ParseResponseCmd(const char * buffer ,U32 bufflen)
{
	std::string tmpjson;
	tmpjson.append( buffer ,bufflen );
	//tmpjson = "{\"message\":\"成功\",\"paramList\":{\"X1MeetingCommon\":{    \"RC_URL\": \"10.130.60.132:10012|10.130.60.132:10012\",   \"MS_URL\": \"10.130.60.132:10013/\",  \"NewRCUrlPort\": 9044,     \"CfgPath\": \"/mnt/internal_sd/meeting/config\",      \"LogFileOutPath\": \"/mnt/internal_sd/meeting/log/logwriter\"     }}, \"status\":\"0\"   }";

	//"{\"message\":\"成功\",\"paramList\":{\"X1MeetingCommon\":\"{\r\n    \"RC_URL\": \"10.130.60.132:10012|10.130.60.132:10012\",\r\n    \"MS_URL\": \"10.130.60.132:10013/\",\r\n    \"NewRCUrlPort\": 9044,\r\n    \"CfgPath\": \"/mnt/internal_sd/meeting/config\",\r\n    \"LogFileOutPath\": \"/mnt/internal_sd/meeting/log/logwriter\"\r\n}\r\n\"},\"status\":\"0\"}";

	Log::writeWarning( N8_AGENT_LOGTYPE , N8_AGENT_LOGSUBID,
		"[AUTO] [NPS] 收到 NPS 查询结果json数据，:%s",tmpjson.c_str());
	Json ::Reader freader;  
	Json::Value root;
	if(!freader.parse(tmpjson,root ) )
	{		
		Log::writeError( N8_AGENT_LOGTYPE , N8_AGENT_LOGSUBID,
			"[AUTO] [NPS] 无法解析 NPS 查询结果json数据，:%s",tmpjson.c_str());
		return -1;		
	}

	Json::Value stusinfo = root["status"];
	if( stusinfo.empty()  )
	{
		Log::writeError(  N8_AGENT_LOGTYPE , N8_AGENT_LOGSUBID,
			"[AUTO] [NPS] 收到 NPS 查询响应命令，无法解析结果json数据[status]:%s",tmpjson.c_str() );
		return -2;
	}

	Json::Value msginfo = root["message"]	;
	if( msginfo.empty() )
	{
		Log::writeError(  N8_AGENT_LOGTYPE , N8_AGENT_LOGSUBID,
			"[AUTO] [NPS] 收到 NPS 查询响应命令，无法解析结果json数据[message]，结束:%s",tmpjson.c_str() );
		return -3;
	}
	m_message = msginfo.asString();

	m_status = atoi( stusinfo.asString().c_str() ) ;
	if( m_status != 0 )
	{
		Log::writeError(  N8_AGENT_LOGTYPE , N8_AGENT_LOGSUBID,
			"[AUTO] [NPS] 收到 NPS 查询响应命令，受到错误码:%d ,描述:%s",m_status , m_message.c_str() );
		return -5;

	}

	Json::Value parmlistinfo = root["paramList"]	;
	if( parmlistinfo.empty() )
	{
		Log::writeError(  N8_AGENT_LOGTYPE , N8_AGENT_LOGSUBID,
			"[AUTO] [NPS] 收到 NPS 查询响应命令，无法解析结果json数据[paramList]，结束:%s",tmpjson.c_str() );
		return -4;
	}

	int iret  =0;

	//iret =  m_common.ParseResponseCmd(parmlistinfo);
	//if( iret != 0)
	//{
	//	Log::writeError(  N8_AGENT_LOGTYPE , N8_AGENT_LOGSUBID,
	//		"[AUTO] [NPS] 收到 NPS 查询响应命令，无法解析结果json数据[NPSX1MeetingCommon]，结束:%s",tmpjson.c_str() );

	//}

	iret =  m_appup.ParseResponseCmd(parmlistinfo);
	if( iret != 0)
	{
		Log::writeError(  N8_AGENT_LOGTYPE , N8_AGENT_LOGSUBID,
			"[AUTO] [NPS] 收到 NPS 查询响应命令，无法解析结果json数据[NPSX1MeetingAppUpdate]，结束:%s",tmpjson.c_str() );

	}

	iret =  m_appupx86.ParseResponseCmd( parmlistinfo,true );
	if( iret != 0)
	{
		Log::writeError(  N8_AGENT_LOGTYPE , N8_AGENT_LOGSUBID,
			"[AUTO] [NPS] 收到 NPS 查询响应命令，无法解析结果json数据[NPSX86MeetingAppUpdate]，结束:%s",tmpjson.c_str() );

	}

	
	return iret;

	return 0;
}
/////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////
I32 UpdateResult::ParseResponseCmd(const char * buffer ,U32 bufflen)
{
	std::string tmpjson;
	tmpjson.append( buffer ,bufflen );

	Json ::Reader freader;  
	Json::Value root;
	if(!freader.parse(tmpjson,root ) )
	{		
		Log::writeError( N8_AGENT_LOGTYPE , N8_AGENT_LOGSUBID,
			"[AUTO] [VERQ] 无法解析查询结果json数据，版本更新结束:%s",tmpjson.c_str());
		return -1;		
	}

	Json::Value resinfo = root["result"];
	if( resinfo.empty())
	{
		Log::writeError(  N8_AGENT_LOGTYPE , N8_AGENT_LOGSUBID,
			"[AUTO] [VERQ] 收到版本查询响应命令，无法解析结果json数据[result]，版本更新结束:%s",tmpjson.c_str() );
		return -2;
	}
	Json::Value rcinfo = resinfo["rc"]	;
	if( rcinfo.empty() || ! rcinfo.isInt() )
	{
		Log::writeError(  N8_AGENT_LOGTYPE , N8_AGENT_LOGSUBID,
			"[AUTO] [VERQ] 收到版本查询响应命令，无法解析结果json数据[result->rc]，版本更新结束:%s",tmpjson.c_str() );
		return -3;
	}
	m_rccode = rcinfo.asInt();
 
	Json::Value rdinfo = resinfo["rd"]	;
	if( rdinfo.empty() || ! rdinfo.isString() )
	{
		Log::writeError(  N8_AGENT_LOGTYPE , N8_AGENT_LOGSUBID,
			"[AUTO] [VERQ] 收到版本查询响应命令，无法解析结果json数据[result->rd]，版本更新结束:%s",tmpjson.c_str() );
		return -3;
	}
	m_rcdsp = rdinfo.asString();
	if( 1 !=  m_rccode )  //1 为升级，其他为不升级。
	{
		Log::writeError(N8_AGENT_LOGTYPE , N8_AGENT_LOGSUBID,
			"[AUTO] [VERQ]  版本查询结果解析 不需要更新，后面数据不进行解析,:%d,%s",m_rccode,m_rcdsp.c_str());
		return 0;
	}

	Json::Value rsp_info = root["response"];
	if(   rsp_info.empty() )
	{
		Log::writeError(N8_AGENT_LOGTYPE , N8_AGENT_LOGSUBID,
			"[AUTO] [VERQ]  版本查询结果解析  Error no response info section");
		return -4;
	}
	else
	{
		Json::Value updp_info = rsp_info["updator"];
		if( updp_info.empty() || ! updp_info.isString() )
		{
			Log::writeError(N8_AGENT_LOGTYPE , N8_AGENT_LOGSUBID,
				"[AUTO] [VERQ]  版本查询结果解析  Error no [updator] info section");
			return -5;
		}

		m_updaotorurl = updp_info.asString();

		Json::Value pkg_info = rsp_info["installer"];
		if( pkg_info.empty() || ! pkg_info.isString() )
		{
			Log::writeError(N8_AGENT_LOGTYPE , N8_AGENT_LOGSUBID,
				"[AUTO] [VERQ]  版本查询结果解析  Error no [installer] info section");
			return -6;
		}

		m_installer = pkg_info.asString();


		Json::Value inval_info = rsp_info["interval"];
		if( inval_info.empty() || ! inval_info.isInt() )
		{
			Log::writeError(N8_AGENT_LOGTYPE , N8_AGENT_LOGSUBID,
				"[AUTO] [VERQ]  版本查询结果解析  Error no [interval] info section");
			return -6;
		}
		m_interval = inval_info.asInt();


		Json::Value ver_info = rsp_info["version"];
		if( ver_info.empty() || ! ver_info.isString() )
		{
			Log::writeError(N8_AGENT_LOGTYPE , N8_AGENT_LOGSUBID,
				"[AUTO] [VERQ]  版本查询结果解析  Error no [version] info section");
		}
		else
		{
			if( ver_info.asString().length() > 1 )
			{				
				m_version = ver_info.asString() ;
				m_version.erase(0,1);				
			}

		}


		Json::Value compat_info = rsp_info["compatible"];
		if( compat_info.empty() || ! compat_info.isInt() )
		{
			Log::writeError(N8_AGENT_LOGTYPE , N8_AGENT_LOGSUBID,
				"[AUTO] [VERQ]  版本查询结果解析  Error no [compatible] info section");
			return -7;
		}
		m_compatible = compat_info.asInt();

	}

	return 0;

}
	


