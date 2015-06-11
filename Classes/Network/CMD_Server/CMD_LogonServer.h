#ifndef CMD_LONGON_HEAD_FILE
#define CMD_LONGON_HEAD_FILE

#include "Define.h"
#include "Struct.h"
#pragma pack(1)
//如果是android平台需要定义宏
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID||CC_TARGET_PLATFORM==CC_PLATFORM_IOS)

#endif
//////////////////////////////////////////////////////////////////////////////////
//登录命令

#define MDM_GP_LOGON				1									//广场登录

//登录模式
#define SUB_GP_LOGON_GAMEID			1									//I D 登录
#define SUB_GP_LOGON_ACCOUNTS		2									//帐号登录
#define SUB_GP_REGISTER_ACCOUNTS	3									//注册帐号
#define SUB_GP_LOGON_LOGOUT_GAMEID  4                                   //退出大厅
#define SUB_GP_LOBBY_IP 			5									//比赛服务器ip

//登录结果
#define SUB_GP_LOGON_SUCCESS		100									//登录成功
#define SUB_GP_LOGON_FAILURE		101									//登录失败
#define SUB_GP_LOGON_FINISH			102									//登录完成
#define SUB_GP_VALIDATE_MBCARD      103                                 //登录失败

//升级提示
#define SUB_GP_UPDATE_NOTIFY		200									//升级提示

//////////////////////////////////////////////////////////////////////////////////
//

#define MB_VALIDATE_FLAGS           0x01                                //效验密保
#define LOW_VER_VALIDATE_FLAGS      0x02                                //效验低版本

//I D 登录
struct CMD_GP_LogonGameID
{
	//系统信息
	DWORD							dwPlazaVersion;						//广场版本
	TCHAR							szMachineID[LEN_MACHINE_ID];		//机器序列
	TCHAR							szPassPortID[LEN_PASS_PORT_ID];		 //身份证号（身份证绑定使用）
	TCHAR							szPhoneVerifyID[LEN_PHONE_VERIFY_ID];//手机验证号（手机绑定使用）

	//登录信息
	DWORD							dwGameID;							//游戏 I D
	TCHAR							szPassword[LEN_MD5];				//登录密码
	BYTE							cbValidateFlags;			        //校验标识
};

//帐号登录
struct CMD_GP_LogonAccounts
{
	//系统信息
	DWORD							dwPlazaVersion;						//广场版本
	TCHAR							szMachineID[LEN_MACHINE_ID];		//机器序列
	TCHAR							szPassPortID[LEN_PASS_PORT_ID];		 //身份证号（身份证绑定使用）
	TCHAR							szPhoneVerifyID[LEN_PHONE_VERIFY_ID];//手机验证号（手机绑定使用）

	//登录信息
	TCHAR							szPassword[LEN_MD5];				//登录密码
	TCHAR							szAccounts[LEN_ACCOUNTS];			//登录帐号
	BYTE							cbValidateFlags;			        //校验标识
};

//注册帐号
struct CMD_GP_RegisterAccounts
{
	//系统信息
	DWORD							dwPlazaVersion;						//广场版本
	TCHAR							szMachineID[LEN_MACHINE_ID];		//机器序列

	//密码变量
	TCHAR							szLogonPass[LEN_MD5];				//登录密码
	TCHAR							szInsurePass[LEN_MD5];				//银行密码

	//注册信息
	WORD							wFaceID;							//头像标识
	BYTE							cbGender;							//用户性别
	TCHAR							szAccounts[LEN_ACCOUNTS];			//登录帐号
	TCHAR							szNickName[LEN_NICKNAME];			//用户昵称
	TCHAR							szSpreader[LEN_ACCOUNTS];			//推荐帐号
	TCHAR							szPassPortID[LEN_PASS_PORT_ID];		//证件号码
	TCHAR							szCompellation[LEN_COMPELLATION];	//真实名字
	BYTE							cbValidateFlags;			        //校验标识
};

//大厅服务器
struct CMD_GP_LobbyIp
{
	DWORD							dwUserID;							//用户 I D
	SCORE                           lIngot;							    //元宝
	SCORE							lUserScore;							//用户金币
	TCHAR							szServerIP[LEN_ADDR];
	DWORD							dwServerPort; 
};

/*//登录成功
struct CMD_GP_LogonSuccess
{
	//属性资料
	WORD							wFaceID;							//头像标识
	DWORD							dwUserID;							//用户 I D
	DWORD							dwGameID;							//游戏 I D
	DWORD							dwGroupID;							//社团标识
	DWORD							dwCustomID;							//自定标识
	DWORD							dwUserMedal;						//用户奖牌
	DWORD							dwExperience;						//经验数值
	DWORD							dwLoveLiness;						//用户魅力

	//用户成绩
	SCORE                           lUserIngot;                            //元宝
	SCORE							lUserScore;							//用户金币
	SCORE							lUserInsure;						//用户银行

	//用户信息
	BYTE							cbGender;							//用户性别
	BYTE							cbMoorMachine;						//锁定机器
	BYTE							cbMoorPassPortID;					//锁定身份证
	BYTE							cbMoorPhone;						//锁定手机
	TCHAR							szPassPortID[LEN_PASS_PORT_ID];		//身份证号（身份证绑定使用）
	TCHAR							szPhoneVerifyID[LEN_MOBILE_PHONE];  //手机号

	TCHAR							szAccounts[LEN_ACCOUNTS];			//登录帐号
	TCHAR							szNickName[LEN_ACCOUNTS];			//用户昵称
	TCHAR							szGroupName[LEN_GROUP_NAME];		//社团名字
	//配置信息
	BYTE                            cbShowServerStatus;                 //显示服务器状态
};*/
//登录成功
struct CMD_GP_LogonSuccess
{
	//属性资料
	WORD								wFaceID;							//头像标识
	DWORD							dwUserID;							//用户 I D
	DWORD							dwGameID;							//游戏 I D
	DWORD							dwGroupID;							//社团标识
	DWORD							dwCustomID;							//自定标识
	DWORD							dwUserMedal;						//用户奖牌
	DWORD							dwExperience;						//经验数值
	DWORD							dwLoveLiness;						//用户魅力
	DWORD                           dwVipLevel;							//金币等级

	//用户成绩
	SCORE                           lIngot;                            //元宝
	SCORE							lUserScore;							//用户金币
	SCORE							lUserInsure;						//用户银行
	SCORE							lIngotScore;						//元宝

	//用户信息
	BYTE							cbGender;							//用户性别
	BYTE							cbMoorMachine;						//锁定机器
	BYTE							cbMoorPassPortID;					//锁定身份证
	BYTE							cbMoorPhone;						//锁定手机
	TCHAR							szPassPortID[LEN_PASS_PORT_ID];		//身份证号（身份证绑定使用）
	TCHAR							szPhoneVerifyID[LEN_MOBILE_PHONE];  //手机号

	TCHAR							szAccounts[LEN_ACCOUNTS];			//登录帐号
	TCHAR							szNickName[LEN_ACCOUNTS];			//用户昵称
	TCHAR							szGroupName[LEN_GROUP_NAME];		//社团名字
	//配置信息
	BYTE                            cbShowServerStatus;                 //显示服务器状态
};

//登录失败
struct CMD_GP_LogonFailure
{
	long							lResultCode;						//错误代码
	TCHAR							szDescribeString[128];				//描述消息
};

//登陆完成
struct CMD_GP_LogonFinish
{
	WORD							wIntermitTime;						//中断时间
	WORD							wOnLineCountTime;					//更新时间
};

//登录失败
struct CMD_GP_ValidateMBCard
{
	//先注销UINT								uMBCardID;						//机器序列
};

//升级提示
struct CMD_GP_UpdateNotify
{
	BYTE							cbMustUpdate;						//强行升级
	BYTE							cbAdviceUpdate;						//建议升级
	DWORD							dwCurrentVersion;					//当前版本
};

//////////////////////////////////////////////////////////////////////////////////
//携带信息 CMD_GP_LogonSuccess

#define DTP_GP_GROUP_INFO			1									//社团信息
#define DTP_GP_MEMBER_INFO			2									//会员信息
#define	DTP_GP_UNDER_WRITE			3									//个性签名
#define DTP_GP_STATION_URL			4									//主页信息

//社团信息
struct DTP_GP_GroupInfo
{
	DWORD							dwGroupID;							//社团索引
	TCHAR							szGroupName[LEN_GROUP_NAME];		//社团名字
};

//会员信息
struct DTP_GP_MemberInfo
{
	BYTE							cbMemberOrder;						//会员等级
	//先注销SYSTEMTIME						MemberOverDate;						//到期时间
};

//////////////////////////////////////////////////////////////////////////////////
//列表命令

#define MDM_GP_SERVER_LIST			2									//列表信息

//获取命令
#define SUB_GP_GET_LIST				1									//获取列表
#define SUB_GP_GET_SERVER			2									//获取房间
#define SUB_GP_GET_ONLINE			3									//获取在线
#define SUB_GP_GET_COLLECTION		4									//获取收藏

//列表信息
#define SUB_GP_LIST_TYPE			100									//类型列表
#define SUB_GP_LIST_KIND			101									//种类列表
#define SUB_GP_LIST_NODE			102									//节点列表
#define SUB_GP_LIST_PAGE			103									//定制列表
#define SUB_GP_LIST_SERVER			104									//房间列表
#define SUB_GP_VIDEO_OPTION			105									//视频配置

//完成信息
#define SUB_GP_LIST_FINISH			200									//发送完成
#define SUB_GP_SERVER_FINISH		201									//房间完成

//在线信息
#define SUB_GR_KINE_ONLINE			300									//类型在线
#define SUB_GR_SERVER_ONLINE		301									//房间在线

//////////////////////////////////////////////////////////////////////////////////

//获取在线
struct CMD_GP_GetOnline
{
	WORD							wServerCount;						//房间数目
	WORD							wOnLineServerID[MAX_SERVER];		//房间标识
};

//类型在线
struct CMD_GP_KindOnline
{
	WORD							wKindCount;							//类型数目
	tagOnLineInfoKind				OnLineInfoKind[MAX_KIND];			//类型在线
};

//房间在线
struct CMD_GP_ServerOnline
{
	WORD							wServerCount;						//房间数目
	tagOnLineInfoServer				OnLineInfoServer[MAX_SERVER];		//房间在线
};

//////////////////////////////////////////////////////////////////////////////////
//服务命令

#define MDM_GP_USER_SERVICE			3									//用户服务

//账号服务
#define SUB_GP_MODIFY_MACHINE		100									//修改机器
#define SUB_GP_MODIFY_LOGON_PASS	101									//修改密码
#define SUB_GP_MODIFY_INSURE_PASS	102									//修改密码
#define SUB_GP_MODIFY_UNDER_WRITE	103									//修改签名
#define SUB_GP_MODIFY_PASSPORT_ID	104	                                //身份证绑定
#define SUB_GP_VERIFY_INSURE_PASS	105	                                //验证保险柜密码

#define SUB_GP_GIFT 				108									//礼品包
#define SUB_GP_PROPERTY				109									//道具
#define SUB_GP_BUYGIFT				110									//购买礼品包,道具
#define SUB_GP_KNAPSACK				111									//背包
#define SUB_GP_KNAPSACKLOG			112									//背包错误提示
#define SUB_GP_USE_KNAPSACKLOG		113									//使用背包
#define SUB_GP_AUCTION				114									//拍卖品
#define SUB_GP_SELL_AUCTION			115									//出售拍卖品
#define SUB_GP_BUY_AUCTION			116									//购买拍卖品
#define SUB_GP_CANCEL_AUCTION		117									//撤消拍卖品
#define SUB_GP_AUCTION_RECORD		118									//拍卖记录
#define SUB_GP_MYAUCTION_RECORD		119									//我的拍卖
#define SUB_GP_AUCTION_HISTORY_RECORD	120								//拍卖历史记录
#define SUB_GP_QUERY_AUCTION		121									//查询拍卖记录
#define SUB_GP_AUCTIONLOG			122									//获取拍卖品

//修改头像
#define SUB_GP_USER_FACE_INFO		200									//头像信息
#define SUB_GP_SYSTEM_FACE_INFO		201									//系统头像
#define SUB_GP_CUSTOM_FACE_INFO		202									//自定头像

//个人资料
#define SUB_GP_USER_INDIVIDUAL		301									//个人资料
#define	SUB_GP_QUERY_INDIVIDUAL		302									//查询信息
#define SUB_GP_MODIFY_INDIVIDUAL	303									//修改资料

//银行服务
#define SUB_GP_USER_SAVE_SCORE		400									//存款操作
#define SUB_GP_USER_TAKE_SCORE		401									//取款操作
#define SUB_GP_USER_TRANSFER_SCORE	402									//转账操作
#define SUB_GP_USER_INSURE_INFO		403									//银行资料
#define SUB_GP_QUERY_INSURE_INFO	404									//查询银行
#define SUB_GP_USER_INSURE_SUCCESS	405									//银行成功
#define SUB_GP_USER_INSURE_FAILURE	406									//银行失败
#define SUB_GP_QUERY_USER_INFO_REQUEST	407								//查询用户
#define SUB_GP_QUERY_USER_INFO_RESULT	408								//用户信息
#define SUB_GP_GET_ALMS             409                                 //领取救济金     
#define SUB_GP_INSURE_RECORD        410                                 //银行记录   

//操作结果
#define SUB_GP_OPERATE_SUCCESS		900									//操作成功
#define SUB_GP_OPERATE_FAILURE		901									//操作失败
//////////////////////////////////////////////////////////////////////////
#define  GIFT_NAME_LEN		16
#define  GIFT_IMGNAME		32
#define  NAME_LEN			16
#define  BUY_PRICE_COUNT	3
#define  AWARD_COUNT		6
#define	 DESPICT_LEN		32
#define  GIFT_COUNT			30
#define  NOTE_LEN			64

//商店////////////////////////////////////////礼品/////////////////////////////
//通过什么途径购买
struct CMD_GP_Buy_Price
{
	CMD_GP_Buy_Price()
	{
		//memset(this, 0, sizeof(CMD_GP_Buy_Price));
	}
	DWORD	dwCount;
	TCHAR   szName[NAME_LEN];
};
//礼品
struct CMD_GP_Gift
{
	CMD_GP_Gift()
	{
		//memset(this, 0, sizeof(CMD_GP_Gift));
	}
	DWORD				dwID;
	TCHAR				szName[GIFT_NAME_LEN];
	TCHAR				szImgName[GIFT_IMGNAME];
	CMD_GP_Buy_Price	price[BUY_PRICE_COUNT];
	DWORD				dwDiscount;								//vip折扣（1-9）
	TCHAR				szOpenDespict[DESPICT_LEN * 2];			//包含的物品描述
	TCHAR				szDespict[DESPICT_LEN];					//描述 

};
struct CMD_GP_BuyGift
{
	CMD_GP_BuyGift()
	{
		//memset(this, 0, sizeof(CMD_GP_BuyGift));
	}
	DWORD			    dwUserID;								//id
	DWORD				dwOpTerminal;							//操作终端（1：pc, 2：手机）
	TCHAR				szLogonPass[LEN_MD5];					//登录密码
	DWORD				dwType;									//类别1:礼包，2:道具
	DWORD				dwID;									//礼包或道具id
	DWORD				dwNum;									//数量
	DWORD				dwBuyMethod;							//购买方法：1：金币，2：元宝，3：红包，4：奖券
	//TCHAR				szNote[NOTE_LEN];						//描述消息
	TCHAR				szMachineID[LEN_MACHINE_ID];			//机器序列
};

struct CMD_GP_BuyGiftLog
{
	CMD_GP_BuyGiftLog()
	{
		//memset(this, 0, sizeof(CMD_GP_BuyGiftLog));
	}
	DWORD							dwRet;								//0：成功，1：失败
	TCHAR							szDescribeString[128];				//描述消息
};
///////////////////////////////////////礼品///////////////////////////////////////
//查询背包信息
struct CMD_GP_UserID
{
	CMD_GP_UserID()
	{
		//memset(this, 0, sizeof(CMD_GP_UserID));
	}
	DWORD							dwUserID;							//用户 I D
	TCHAR							szPassword[LEN_PASSWORD];			//用户密码
};
struct CMD_GP_Knapsack
{
	CMD_GP_Knapsack()
	{
		//memset(this, 0, sizeof(CMD_GP_Knapsack));
	}
	DWORD				dwID;
	DWORD				dwPackType;								//类别1:礼包，2:道具
	DWORD				dwPropID;								//礼包或道具id
	DWORD				dwNum;									//数量
	DWORD				dwSortID;								//顺序
	TCHAR				szName[GIFT_NAME_LEN];					//名称
	TCHAR				szImgName[GIFT_IMGNAME];				//图片
};
struct CMD_GP_KnapsackLog
{
	CMD_GP_KnapsackLog()
	{
		//memset(this, 0, sizeof(CMD_GP_KnapsackLog));
	}
	DWORD							dwRet;								//0：成功，1：失败
	TCHAR							szDescribeString[128];				//描述消息
};
//使用背包
struct CMD_GP_UseKnapsack
{
	CMD_GP_UseKnapsack()
	{
		//memset(this, 0, sizeof(CMD_GP_UseKnapsack));
	}
	DWORD							dwUserID;							//用户 I D
	DWORD							dwOpTerminal;						//操作终端（1：pc, 2：手机）
	TCHAR							szPassword[LEN_PASSWORD];			//用户密码
	DWORD							dwID;								//背包id
	DWORD							dwNum;								//数量
	TCHAR							szNote[NOTE_LEN];					//描述消息
	TCHAR							szMachineID[LEN_MACHINE_ID];		//机器序列
};
struct CMD_GP_UseKnapsackLog
{
	CMD_GP_UseKnapsackLog()
	{
		//memset(this, 0, sizeof(CMD_GP_UseKnapsackLog));
	}
	DWORD							dwRet;								//0：成功，1：失败
	DWORD							dwID;								//背包id
	DWORD							dwNum;								//使用的数量
	TCHAR							szDescribeString[128];				//描述消息
};

//////////////////////////////////////////////////////////////////////////
struct CMD_GP_Auction
{
	CMD_GP_Auction()
	{
		//memset(this, 0, sizeof(CMD_GP_Auction));
	}
	DWORD				dwID;
	DWORD				dwPackType;								//类别1:礼包，2:道具
	DWORD				dwPropID;								//礼包或道具id
	DWORD				dwNum;									//数量
	DWORD				dwSortID;								//顺序
	TCHAR				szName[GIFT_NAME_LEN];					//名称
	TCHAR				szImgName[GIFT_IMGNAME];				//图片
};
//获取我的上架物品
struct  CMD_GP_AuctionLog
{
	CMD_GP_AuctionLog()
	{
		//memset(this, 0, sizeof(CMD_GP_AuctionLog));
	}
	DWORD							dwRet;								//0：成功，1：失败
	TCHAR							szDescribeString[128];				//描述消息
};
//拍卖品上架
struct CMD_GP_Sell_Auction
{
	CMD_GP_Sell_Auction()
	{
		//memset(this, 0, sizeof(CMD_GP_Sell_Auction));
	}
	DWORD			    dwUserID;								//id
	DWORD				dwOpTerminal;							//操作终端（1：pc, 2：手机）
	TCHAR				szLogonPass[LEN_MD5];					//登录密码
	DWORD				dwID;									//礼包或道具id
	SCORE				lGold;									//价格
	DWORD				dwNum;									//数量
	TCHAR				szMachineID[LEN_MACHINE_ID];			//机器序列
};
//购买拍卖品
struct CMD_GP_Buy_Auction
{
	CMD_GP_Buy_Auction()
	{
		//memset(this, 0, sizeof(CMD_GP_Buy_Auction));
	}
	DWORD			    dwUserID;								//id
	DWORD				dwOpTerminal;							//操作终端（1：pc, 2：手机）
	TCHAR				szLogonPass[LEN_MD5];					//登录密码
	DWORD				dwID;									//礼包或道具id
	DWORD				dwNum;									//数量
	TCHAR				szMachineID[LEN_MACHINE_ID];			//机器序列
};
//拍卖品撤消
struct CMD_GP_Cancel_Auction
{
	CMD_GP_Cancel_Auction()
	{
		//memset(this, 0, sizeof(CMD_GP_Cancel_Auction));
	}
	DWORD			    dwUserID;								//id
	DWORD				dwOpTerminal;							//操作终端（1：pc, 2：手机）
	TCHAR				szLogonPass[LEN_MD5];					//登录密码
	DWORD				dwID;									//礼包或道具id
	TCHAR				szMachineID[LEN_MACHINE_ID];			//机器序列
};
//查找拍卖记录
struct CMD_GP_Query_Auction
{
	CMD_GP_Query_Auction()
	{
		//memset(this, 0, sizeof(CMD_GP_Query_Auction));
	}
	TCHAR				szID[LEN_ACCOUNTS];							//GameID 或 昵称
	DWORD								dwPage;							//查询第几页
	DWORD								dwPageSize;						//每页大小，缺省为10
	DWORD								dwLastDay;						//时间
};
//获取拍卖记录
struct CMD_GP_GetAuctionRecord
{
	DWORD								dwUserID;
	DWORD								dwPage;							//查询第几页
	DWORD								dwPageSize;						//每页大小，缺省为10
	DWORD								dwLastDay;						//时间
};
//拍卖记录
struct CMD_GP_AuctionRecordItem
{
	DWORD								dwIndex;						//单号
	DWORD								dwGameID;
	TCHAR								szNickName[LEN_ACCOUNTS];		//昵称
	TCHAR								szAuctionName[NAME_LEN];		//拍卖品名称
	DWORD								dwPropNum;
	long long							lGold;							//价格
};
//我的拍卖
struct CMD_GP_MyAuctionRecordItem
{
	DWORD								dwIndex;						//单号
	TCHAR								szAuctionName[NAME_LEN];		//拍卖品名称
	DWORD								dwPropNum;
	long long							lGold;							//价格
};
//拍卖记录
struct CMD_GP_HistoryAuctionRecordItem
{
	DWORD								dwIndex;						//单号
	DWORD								dwGameID;
	TCHAR								szNickName[LEN_ACCOUNTS];		//昵称
	TCHAR								szAuctionName[NAME_LEN];		//拍卖品名称
	DWORD								dwType;							//类型1:买，2:卖
	DWORD								dwPropNum;
	long long							lGold;							//价格
	SYSTEMTIME							tOpDate;
};
//记录
template <class T>
struct CMD_GP_AuctionRecord
{
	DWORD								dwPageCount;					//页码总数
	DWORD								dwPageIndex;					//查询第几页
	DWORD								dwIndex;						//条数
	T									RecordItem[20];
};
struct CMD_GP_Sell_AuctionLog
{
	CMD_GP_Sell_AuctionLog()
	{
		//memset(this, 0, sizeof(CMD_GP_Sell_AuctionLog));
	}
	DWORD							dwRet;								//0：成功，1：失败
	DWORD							dwID;								//礼包或道具id
	SCORE							lGold;								//价格
	DWORD							dwNum;								//数量							
	TCHAR							szDescribeString[128];				//描述消息
};
struct CMD_GP_Buy_AuctionLog
{
	CMD_GP_Buy_AuctionLog()
	{
		//memset(this, 0, sizeof(CMD_GP_Buy_AuctionLog));
	}
	DWORD							dwRet;								//0：成功，非0：失败
	DWORD							dwID;								//礼包或道具id
	SCORE							lGold;								//价格					
	TCHAR							szDescribeString[128];				//描述消息
};
struct CMD_GP_Cancel_AuctionLog
{
	CMD_GP_Cancel_AuctionLog()
	{
		//memset(this, 0, sizeof(CMD_GP_Cancel_AuctionLog));
	}
	DWORD							dwRet;								//0：成功，1：失败
	DWORD							dwID;
	DWORD							dwNum;								//数量
	DWORD							dwSortID;							//顺序
	TCHAR							szName[GIFT_NAME_LEN];				//名称
	TCHAR							szImgName[GIFT_IMGNAME];			//图片		
	TCHAR							szDescribeString[128];				//描述消息
};
//////////////////////////////////////////////////////////////////////////////////

//修改密码
struct CMD_GP_ModifyLogonPass
{
	DWORD							dwUserID;							//用户 I D
	TCHAR							szDesPassword[LEN_PASSWORD];		//用户密码
	TCHAR							szScrPassword[LEN_PASSWORD];		//用户密码
};

//修改密码
struct CMD_GP_ModifyInsurePass
{
	DWORD							dwUserID;							//用户 I D
	TCHAR							szDesPassword[LEN_PASSWORD];		//用户密码
	TCHAR							szScrPassword[LEN_PASSWORD];		//用户密码
};

//修改签名
struct CMD_GP_ModifyUnderWrite
{
	DWORD							dwUserID;							//用户 I D
	TCHAR							szPassword[LEN_PASSWORD];			//用户密码
	TCHAR							szUnderWrite[LEN_UNDER_WRITE];		//个性签名
};

//////////////////////////////////////////////////////////////////////////////////

//用户头像
struct CMD_GP_UserFaceInfo
{
	WORD							wFaceID;							//头像标识
	DWORD							dwCustomID;							//自定标识
};

//修改头像
struct CMD_GP_SystemFaceInfo
{
	WORD							wFaceID;							//头像标识
	DWORD							dwUserID;							//用户 I D
	TCHAR							szPassword[LEN_PASSWORD];			//用户密码
	TCHAR							szMachineID[LEN_MACHINE_ID];		//机器序列
};

//修改头像
struct CMD_GP_CustomFaceInfo
{
	DWORD							dwUserID;							//用户 I D
	TCHAR							szPassword[LEN_PASSWORD];			//用户密码
	TCHAR							szMachineID[LEN_MACHINE_ID];		//机器序列
	DWORD							dwCustomFace[FACE_CX*FACE_CY];		//图片信息
};

//////////////////////////////////////////////////////////////////////////////////

//绑定机器
struct CMD_GP_ModifyMachine
{
	BYTE							cbBind;								//绑定标志
	DWORD							dwUserID;							//用户标识
	TCHAR							szPassword[LEN_PASSWORD];			//用户密码
	TCHAR							szMachineID[LEN_MACHINE_ID];		//机器序列
};

//绑定身份证
struct CMD_GP_ModifyPassPortID
{
	BYTE							cbBind;								//绑定标志
	DWORD							dwUserID;							//用户标识
	TCHAR							szPassword[LEN_PASSWORD];			//用户密码
	TCHAR							szMachineID[LEN_MACHINE_ID];		//机器序列
	TCHAR							szName[LEN_COMPELLATION];			//真实性名
	TCHAR							szPassPortID[LEN_PASS_PORT_ID];		//身份证号（身份证绑定使用）
};
//////////////////////////////////////////////////////////////////////////////////

//个人资料
struct CMD_GP_UserIndividual
{
	DWORD							dwUserID;							//用户 I D
};

//查询信息
struct CMD_GP_QueryIndividual
{
	DWORD							dwUserID;							//用户 I D
	TCHAR							szPassword[LEN_PASSWORD];			//用户密码
};

//修改资料
struct CMD_GP_ModifyIndividual
{
	BYTE							cbGender;							//用户性别
	DWORD							dwUserID;							//用户 I D
	TCHAR							szPassword[LEN_PASSWORD];			//用户密码
};

//////////////////////////////////////////////////////////////////////////////////
//携带信息 CMD_GP_UserIndividual

#define DTP_GP_UI_NICKNAME			1									//用户昵称
#define DTP_GP_UI_USER_NOTE			2									//用户说明
#define DTP_GP_UI_UNDER_WRITE		3									//个性签名
#define DTP_GP_UI_QQ				4									//Q Q 号码
#define DTP_GP_UI_EMAIL				5									//电子邮件
#define DTP_GP_UI_SEAT_PHONE		6									//固定电话
#define DTP_GP_UI_MOBILE_PHONE		7									//移动电话
#define DTP_GP_UI_COMPELLATION		8									//真实名字
#define DTP_GP_UI_DWELLING_PLACE	9									//联系地址

//////////////////////////////////////////////////////////////////////////////////

//银行资料
struct CMD_GP_UserInsureInfo
{
	WORD							wRevenueTake;						//税收比例
	WORD							wRevenueTransfer;					//税收比例
	WORD							wServerID;							//房间标识
	SCORE							lUserScore;							//用户金币
	SCORE							lUserInsure;						//银行金币
	SCORE							lTransferPrerequisite;				//转账条件
	SCORE                           lUserIngot;                         //用户元宝
	SCORE                           lUserLoveliness;                    //用户魅力
};

//存入金币
struct CMD_GP_UserSaveScore
{
	DWORD							dwUserID;							//用户 I D
	SCORE							lSaveScore;							//存入金币
	TCHAR							szMachineID[LEN_MACHINE_ID];		//机器序列
};

//提取金币
struct CMD_GP_UserTakeScore
{
	DWORD							dwUserID;							//用户 I D
	SCORE							lTakeScore;							//提取金币
	TCHAR							szPassword[LEN_MD5];				//银行密码
	TCHAR							szMachineID[LEN_MACHINE_ID];		//机器序列
};

//转账金币
struct CMD_GP_UserTransferScore
{
	DWORD							dwUserID;							//用户 I D
	BYTE                            cbByNickName;                       //昵称赠送
	SCORE							lTransferScore;						//转账金币
	TCHAR							szPassword[LEN_MD5];				//银行密码
	TCHAR							szNickName[LEN_NICKNAME];			//目标用户
	TCHAR							szMachineID[LEN_MACHINE_ID];		//机器序列
};

//银行成功
struct CMD_GP_UserInsureSuccess
{
	DWORD							dwUserID;							//用户 I D
	SCORE							lUserScore;							//用户金币
	SCORE							lUserInsure;						//银行金币
	SCORE							lSwapScore;							//币赠送
	DWORD							dwGameID;
	TCHAR							szNickName[LEN_NICKNAME];
	DWORD							dwTargetGameID;
	TCHAR							szTargetNickName[LEN_NICKNAME];
	DWORD							dwRecordID;
	TCHAR							szDate[32];							//日期
	TCHAR							szDescribeString[128];				//描述消息
};

//银行失败
struct CMD_GP_UserInsureFailure
{
	long							lResultCode;						//错误代码
	TCHAR							szDescribeString[128];				//描述消息
};

//提取结果
struct CMD_GP_UserTakeResult
{
	DWORD							dwUserID;							//用户 I D
	SCORE							lUserScore;							//用户金币
	SCORE							lUserInsure;						//银行金币
};

//查询银行
struct CMD_GP_QueryInsureInfo
{
	DWORD							dwUserID;							//用户 I D
	TCHAR							szPassword[LEN_MD5];				//银行密码
};

//查询用户
struct CMD_GP_QueryUserInfoRequest
{
	BYTE                            cbByNickName;                       //昵称赠送
	TCHAR							szNickName[LEN_NICKNAME];			//目标用户
};

//领取救济金
struct CMD_GP_GetAlms
{
	DWORD							dwUserID;						    //用户
	TCHAR							szPassword[LEN_MD5];			    //用户密码
	TCHAR							szMachineID[LEN_MACHINE_ID];		//机器序列
};

//验证保险柜密码
struct CMD_GP_VERIFY_INSUREPASS
{
	DWORD                           dwUserID;
	TCHAR							szInsurePass[LEN_MD5];			    //保险柜密码
	TCHAR							szMachineID[LEN_MACHINE_ID];		//机器序列
};

//用户信息
struct CMD_GP_UserTransferUserInfo
{
	DWORD							dwTargetGameID;						//目标用户
	TCHAR							szNickName[LEN_NICKNAME];			//目标用户
};
//////////////////////////////////////////////////////////////////////////////////

//操作失败
struct CMD_GP_OperateFailure
{
	long							lResultCode;						//错误代码
	TCHAR							szDescribeString[128];				//描述消息
};

//操作成功
struct CMD_GP_OperateSuccess
{
	long							lResultCode;						//操作代码
	TCHAR							szDescribeString[128];				//成功消息
};

//领取救济金
struct CMD_GP_GetAlmsSuccess
{
	SCORE							lUserInsure;						//保险柜金币
	TCHAR							szDescribeString[128];				//成功消息
};

//转账日志
struct CMD_GP_GetBankRecord
{
	DWORD								dwUserID;
	DWORD								dwPage;							//查询第几页
	DWORD								dwPageSize;						//每页大小，缺省为10
	DWORD								dwLastDay;						//时间
};


struct CMD_GP_BankRecordItem
{
	DWORD								dwIndex;						//单号
	DWORD								dwUserID;		
	TCHAR								szNickName[LEN_ACCOUNTS];		//昵称
	DWORD								bType;							//类型(1转出 2转入)
	long long							lTransferCount;                 //转出数目
	//先注销SYSTEMTIME							tTransferDate;
};

struct CMD_GP_BankRecord
{
	DWORD								dwPageCount;					//页码总数
	DWORD								dwPageIndex;					//查询第几页
	DWORD								dwIndex;						//条数
	CMD_GP_BankRecordItem				RecordItem[20];
};


//////////////////////////////////////////////////////////////////////////////////
//远程服务

#define MDM_GP_REMOTE_SERVICE		4									//远程服务

//查找服务
#define SUB_GP_C_SEARCH_DATABASE	100									//数据查找
#define SUB_GP_C_SEARCH_CORRESPOND	101									//协调查找

//查找服务
#define SUB_GP_S_SEARCH_DATABASE	200									//数据查找
#define SUB_GP_S_SEARCH_CORRESPOND	201									//协调查找

//////////////////////////////////////////////////////////////////////////////////

//协调查找
struct CMD_GP_C_SearchCorrespond
{
	DWORD							dwGameID;							//游戏标识
	TCHAR							szNickName[LEN_NICKNAME];			//用户昵称
};

//协调查找
struct CMD_GP_S_SearchCorrespond
{
	WORD							wUserCount;							//用户数目
	tagUserRemoteInfo				UserRemoteInfo[16];					//用户信息
};

//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////

//登录命令
#define MDM_MB_LOGON				100									//广场登录

//登录模式
#define SUB_MB_LOGON_GAMEID			1									//I D 登录
#define SUB_MB_LOGON_ACCOUNTS		2									//帐号登录
#define SUB_MB_REGISTER_ACCOUNTS	3									//注册帐号

//登录结果
#define SUB_MB_LOGON_SUCCESS		100									//登录成功
#define SUB_MB_LOGON_FAILURE		101									//登录失败

//升级提示
#define SUB_MB_UPDATE_NOTIFY		200									//升级提示

//////////////////////////////////////////////////////////////////////////////////

//I D 登录
struct CMD_MB_LogonGameID
{
	//系统信息
	WORD							wModuleID;							//模块标识
	DWORD							dwPlazaVersion;						//广场版本
	BYTE                            cbDeviceType;                       //设备类型

	//登录信息
	DWORD							dwGameID;							//游戏 I D
	TCHAR							szPassword[LEN_MD5];				//登录密码

	//连接信息
	TCHAR							szMachineID[LEN_MACHINE_ID];		//机器标识
	TCHAR							szMobilePhone[LEN_MOBILE_PHONE];	//电话号码
	TCHAR							szPassPortID[LEN_PASS_PORT_ID];		 //身份证号（身份证绑定使用）
	TCHAR							szPhoneVerifyID[LEN_PHONE_VERIFY_ID];//手机验证号（手机绑定使用）
};

//帐号登录
struct CMD_MB_LogonAccounts
{
	//系统信息
	WORD							wModuleID[10];						//模块标识
	DWORD						dwPlazaVersion;						//广场版本
	BYTE                            cbDeviceType;                       //设备类型

	//登录信息
	TCHAR							szPassword[LEN_MD5];				//登录密码
	TCHAR							szAccounts[LEN_ACCOUNTS];			//登录帐号

	//连接信息
	TCHAR							szMachineID[LEN_MACHINE_ID];		//机器标识
	TCHAR							szMobilePhone[LEN_MOBILE_PHONE];	//电话号码
	TCHAR							szPassPortID[LEN_PASS_PORT_ID];		 //身份证号（身份证绑定使用）
	TCHAR							szPhoneVerifyID[LEN_PHONE_VERIFY_ID];//手机验证号（手机绑定使用）
};

//注册帐号
struct CMD_MB_RegisterAccounts
{
	//系统信息
	WORD							wModuleID;							//模块标识
	DWORD						dwPlazaVersion;						//广场版本
	BYTE                            cbDeviceType;                       //设备类型

	//密码变量
	TCHAR							szLogonPass[LEN_MD5];				//登录密码
	TCHAR							szInsurePass[LEN_MD5];				//银行密码

	//注册信息
	WORD							wFaceID;							//头像标识
	BYTE							cbGender;							//用户性别
	TCHAR							szAccounts[LEN_ACCOUNTS];			//登录帐号
	TCHAR							szNickName[LEN_NICKNAME];			//用户昵称

	//连接信息
	TCHAR							szMachineID[LEN_MACHINE_ID];		//机器标识
	TCHAR							szMobilePhone[LEN_MOBILE_PHONE];	//电话号码
};

/*//登录成功
struct CMD_MB_LogonSuccess
{
	WORD							wFaceID;							//头像标识
	BYTE							cbGender;							//用户性别
	DWORD							dwUserID;							//用户 I D
	DWORD							dwGameID;							//游戏 I D
	DWORD							dwExperience;						//经验数值
	DWORD							dwLoveLiness;						//用户魅力
	TCHAR							szNickName[LEN_NICKNAME];			//用户昵称
};*/
//登录成功
struct CMD_MB_LogonSuccess
{
	WORD								wFaceID;							//头像标识
	BYTE								cbGender;							//用户性别
	BYTE							cbInsurePwd;						//重设密码
	DWORD							dwUserID;							//用户 I D
	DWORD							dwGameID;							//游戏 I D
	DWORD							dwExperience;						//经验数值
	SCORE								dwLoveLiness;						//用户魅力

	DWORD                           dwVipLevel;							//金币等级
	SCORE								lIngot;								//元宝
	SCORE								lUserScore;							//用户游戏币
	SCORE								lIngotScore;						//元宝
	SCORE								lUserInsure;						//用户银行

	TCHAR							szNickName[LEN_NICKNAME];			//用户昵称
};


//登录失败
struct CMD_MB_LogonFailure
{
	long							lResultCode;								 //错误代码
	TCHAR						szDescribeString[128];				//描述消息
};

//升级提示
struct CMD_MB_UpdateNotify
{
	BYTE							cbMustUpdate;						//强行升级
	BYTE							cbAdviceUpdate;						//建议升级
	DWORD							dwCurrentVersion;					//当前版本
};

//////////////////////////////////////////////////////////////////////////////////
//列表命令

#define MDM_MB_SERVER_LIST			101									//列表信息

//列表信息
#define SUB_MB_LIST_KIND			100									//种类列表
#define SUB_MB_LIST_SERVER			101									//房间列表
#define SUB_MB_LIST_FINISH			200									//列表完成

//////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
//任务
#define MDM_GL_C_DATA					1								//大厅--客户端数据
#define	SUB_GL_C_TASK_LOAD				114								//加载任务

#define  TASK_TITLE_LEN			16
#define  TASK_TITLE_LEN			32
#define	 TASK_AWARD				8
#define  TASK_INFO_COUNT		20
#define	 IMGNAME				32
#define  PROC_NAME				64
#define  LEN_AWARD				32

struct CMD_GL_GetTask
{
	CMD_GL_GetTask()
	{
		//memset(this, 0, sizeof(CMD_GL_GetTask));
	}
	DWORD				dwOpTerminal;							//操作终端（1：pc, 2：手机）
};
//任务奖励，最多3个
struct CMD_GL_TaskAward
{
	CMD_GL_TaskAward()
	{
		//memset(this, 0, sizeof(CMD_GL_TaskAward));
	}
	DWORD           dwAward1;
	TCHAR			szAward1[LEN_AWARD];
	DWORD           dwAward2;
	TCHAR			szAward2[LEN_AWARD];
	DWORD           dwAward3;
	TCHAR			szAward3[LEN_AWARD];
};
//任务
struct CMD_GL_TaskInfo
{
	CMD_GL_TaskInfo()
	{
		//memset(this, 0, sizeof(CMD_GL_TaskInfo));
	}
	DWORD				dwTaskID;
	TCHAR				szTitle[TASK_TITLE_LEN];
	TCHAR				szImgName[IMGNAME];				//图片
	DWORD				dwSortID;
	CMD_GL_TaskAward	Award;
	TCHAR				szRemarks[TASK_TITLE_LEN];
	DWORD				dwProgress;
	DWORD				dwCurProgress;
};

#pragma pack()

#endif
