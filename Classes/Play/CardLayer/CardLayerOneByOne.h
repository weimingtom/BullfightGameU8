
#pragma once
#include "CardLayerBase.h"
#include "../../GameLogic/GameLogicOneByOne.h"
using namespace gui;
class CardLayerOneByOne:public CardLayerBase,GameLogicOneByOne {
private:

public:
	CardLayerOneByOne();
	~CardLayerOneByOne();
	CREATE_FUNC(CardLayerOneByOne);
	
	virtual void onEnter();
	virtual void onExit();

	virtual void setCanSendCard();
	
    
public:
	//更新状态
	virtual void updateServerState();
	//
	virtual void updateGameState();
	//显示牌
	void showCard(bool isAction, int index, int dataIndex);

	//提示牛牛
	bool promptOx(int oxIndex);
	//重排牛牛
	void sortingOx(int chairID,int showChairiD);
	//发5张牌
	virtual void sendFiveCard(int index, int offsetIndex);
	//获取牌放大倍数
	virtual float getCardScale(int index);

private:

	//发牌中
	virtual void sendCardIng();
	//移动扑克
	virtual void moveCardAction(CCArmature *armature, float fTime, CCPoint targetPos,int index);
	//单张牌发完回调
	void onSendCardFinish(CCNode *node);

	//显示牛牛点数
	void showOxType(int chairiD,int oxType);
	void onPlayOxAnimation(CCNode *obj);
};
