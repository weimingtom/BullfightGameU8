//
//
//
#pragma once
#include "GameControlBase.h"
#include "../OxHundred/SeatData.h"
#include "../OxHundred/JettonNode.h"
//#include "cmd_game.h"
#include "../OxHundred/PlayerDataHundred.h"
#include "../../GameLogic/GameLogicHundred.h"
#include "../OxHundred/ChairData.h"

//class cmd_game;
#define MAX_SEAT_COUNT 4
#define MAX_JETTON_BUTTON_COUNT			5			//筹码按键总数
#define MAX_AREA_COUNT								4			//区域数目
#define MAX_PLAYER_HUNDRED_COUNT			2			//百人牛牛用户数
#define MAX_SCORE_HISTORY							15		//游戏记录最大数
#define MAX_APPLY_DISPLAY							6			//最大申请显示人数

#define MAX_USER_CHAIR						6					//最大用户椅子数
#pragma pack(1)
//记录信息
struct tagGameRecord
{
    
	bool							bWinShunMen;						//顺门胜利
	bool							bWinDuiMen;							//对门胜利
	bool							bWinDaoMen;							//倒门胜利
	bool							bWinHuang;							//倒门胜利
};
struct tagApplyUser
{
	//玩家信息
	std::string							strUserName;						//玩家帐号
	long long							lUserScore;							//玩家金币
};
#pragma pack()

class GameControlOxHundred:public GameControlBase,public GameLogicHundred
{
public:
	long long						llApplyBankerCondition;				//申请条件(上庄条件)
public:
	//tagGameRecord				m_GameRecordArrary[MAX_SCORE_HISTORY];//游戏记录
	std::list <tagGameRecord> listGameRecord;//游戏记录
	std::list <tagApplyUser>     listApplyUser;//申请庄家列表
	bool isChangeUpBank;					//是否可以切换下庄
	//限制信息
protected:
	long long						m_lMeMaxScore;						//最大下注
	long long						m_lAreaLimitScore;					//区域限制
	//下注信息
protected:
	long long						m_lUserJettonScore[MAX_AREA_COUNT+1];	//个人总注
	long long						m_lAllJettonScore[MAX_AREA_COUNT+1];		//全体总注

	
	//庄家信息
public:
	WORD							m_wBankerUser;						//当前庄家
	long long						m_lBankerScore;						//庄家积分
public:

	BYTE							m_bMeApplyBanker;					//申请标识(自己是不是庄家)0不是，1是，2更改中								
private:
	int lJettonState;				//筹码起始下标
	UILayer *pWidget;
	unsigned short m_wCurrentBanker;
	int nJetton[MAX_JETTON_BUTTON_COUNT];
	int nAllJetton[MAX_JETTON_BUTTON_COUNT+3];
	SeatData *pSeatData[MAX_SEAT_COUNT];
	ChairData *pChairData[MAX_USER_CHAIR];
	Button *pBOnline ;
	//筹码按钮
	ImageView *pIJettonButton[MAX_JETTON_BUTTON_COUNT];
	//筹码选择光标
	ImageView *pIJettonSelect;
	//当前所选筹码索引
	int iCurSelectJettonIndex;
	//用户信息
	PlayerDataHundred *pPlayerData[MAX_PLAYER_HUNDRED_COUNT];
	//上庄按键
	ImageView *pIUpBank;
	//游戏结束输赢筹码统计
	long long lUserScore;								//玩家成绩
	long long lBankerScore;								//庄家成绩
	CCPoint posBankJetton;								//庄家筹码位置
	CCPoint posPlayerJetton;							//玩家筹码位置
	//游戏状态
protected:
	bool								m_bAllowLookon;						//允许旁观
	BYTE							m_cbGameStatus;						//游戏状态
public:
	GameControlOxHundred();
	~GameControlOxHundred();
	virtual void onEnter();
	virtual void onExit();
    CREATE_FUNC(GameControlOxHundred);
	//设置座位结算
	void setSeatResult(int iSeatIndex,int iOXType);
	//显示总结果
	void showAllResult();
	//更新状态
	virtual void updateState();
private:

	//初始化计时器
	void initTimer(UILayer *pWidget);
	//初始化座位
	void initSeatData(UILayer *pWidget);
	//初始化用户椅子
	void initUserChair(UILayer *pWidget);
	//获取筹码对象
	JettonNode *getJettonNode();
	//获取用户信息通过椅子号
	tagUserInfo* getUserInfo(int iChair);
	//创建初始筹码
	void createJettonInit(int index, long long num);
private:
	int getChairIndex(int meChairID,int chairID);
	virtual void update(float delta);
	//更新计时器
	virtual void delayedAction();
	//读取网络消息回调事件
	virtual void onEventReadMessage(WORD wMainCmdID,WORD wSubCmdID,void * pDataBuffer, unsigned short wDataSize);
	//框架命令
	void onSubGameFrame(WORD wSubCmdID,void * pDataBuffer, unsigned short wDataSize);
	//系统消息
	virtual void onSocketSubSystemMessage(void * pData, unsigned short wDataSize);
	//游戏中
	void onEventGameIng(WORD wSubCmdID,void * pDataBuffer, unsigned short wDataSize);
	//用户信息
	void onSubUserInfo(WORD wSubCmdID,void * pDataBuffer, unsigned short wDataSize);
	//用户进入
	void onSubUserEnter(void * pDataBuffer, unsigned short wDataSize);
	//用户状态
	void onSubUserState(void * pDataBuffer, unsigned short wDataSize);
	//用户状态
	virtual void onSubUserState(WORD wSubCmdID,void * pDataBuffer, unsigned short wDataSize);
	//用户坐下状态
	void onSubUserSitState(void * pDataBuffer, unsigned short wDataSize);
	//用户起立状态
	void onSubUserUpState(void * pDataBuffer, unsigned short wDataSize);
	//////////////////////////////////////////////////////////////////////////
	//游戏空闲
	void onSubGameFree(const void * pBuffer, WORD wDataSize);
	//开始游戏
	void onSubGameStart(const void * pBuffer, WORD wDataSize);
	//用户下注
	void onSubPlaceJetton(const void * pBuffer, WORD wDataSize,bool bGameMes);
	//下注失败
	void onSubPlaceJettonFail(const void * pBuffer, WORD wDataSize);
	//游戏记录
	void onSubGameRecord(const void * pBuffer, WORD wDataSize);
	//申请庄家
	void onSubUserApplyBanker(const void * pBuffer, WORD wDataSize);
	//取消做庄
	void onSubUserCancelBanker(const void * pBuffer, WORD wDataSize);
	//切换庄家
	void onSubChangeBanker(const void * pBuffer, WORD wDataSize);
	//抢庄
	void onQiangZhuanRet( const void *pBuffer,WORD wDataSize );
	//游戏结束
	void onSubGameEnd(const void * pBuffer, WORD wDataSize);
private:
	//菜单返回////////////////////////////////////////////////////////////////////////
	void onMenuBack(CCObject* pSender, TouchEventType type);
	//充值
	void onMenuOnRecharge(CCObject* pSender, TouchEventType type);
	//在线用户
	void onMenuOnLine(CCObject* pSender, TouchEventType type);
	//趋势图
	void onMenuTrend(CCObject* pSender, TouchEventType type);
	//加注区域
	void onMenuPlaceJetton(CCObject* pSender, TouchEventType type);
	//选择筹码
	void onMenuSelectJetton(CCObject* pSender, TouchEventType type);
	//上庄
	void onMenuUpBank(CCObject* pSender, TouchEventType type);
	//换椅子
	void onMenuChangeChair(CCObject* pSender, TouchEventType type);
	//最大下注
	long long getUserMaxJetton();
	//更新控制
	void updateButtonContron();
	//设置庄家
	void setBankerInfo(unsigned short  wBanker,long long lScore);
	//重置数据
	void resetData();
	//插入历史记录
	void insertGameHistory(tagGameRecord tagRecord);
	//推断赢家
	void deduceWinner(bool &bWinTian, bool &bWinDi, bool &bWinXuan,bool &bWinHuan,BYTE &TianMultiple,BYTE &diMultiple,BYTE &TianXuanltiple,BYTE &HuangMultiple );
public:
	//申请庄家
	void onApplyBanker(bool bApplyBanker);

	//开始下注效果动画
	void beginAddScoreEffect();
	void onAnimationEventOver(CCArmature *pArmature, MovementEventType movementType, const char *movementID);
	void onAnimationEventFrame(CCBone *bone, const char *evt, int originFrameIndex, int currentFrameIndex);

private:
	//分发筹码
	void bankJettonIn(float dt);
	//移动相同筹码(庄家收)
	void moveJettonBankIn(int chairID,CCPoint pos);
	//庄家出
	void moveJettonBankOut(int chairID);
	//玩家收
	void moveJettonPlayerIn(int chairID);
public:
	//庄家出币
	void bankOutJetton();
	//玩家收币
	void playerInJetton();
	//分币完成
	void splitJettonFinish();
};
