//ϵͳ
#ifdef WIN32
#include "stdafx.h"
#endif

#include "vnost.h"
#include "pybind11/pybind11.h"
#include "ost/SecurityDntL2MDUserApi.h"


using namespace pybind11;

//����
#define ONFRONTCONNECTED 0
#define ONRSPSUBFUTUREMARKETDATA 1
#define ONRSPUNSUBFUTUREMARKETDATA 2
#define ONRSPSUBL2MARKETDATA 3
#define ONRSPUNSUBL2MARKETDATA 4
#define ONRSPSUBL1MARKETDATA 5
#define ONRSPUNSUBL1MARKETDATA 6
#define ONRSPSUBL2ORDERANDTRADE 7
#define ONRSPUNSUBL2ORDERANDTRADE 8
#define ONRSPSUBL2INDEXMARKETDATA 9
#define ONRSPUNSUBL2INDEXMARKETDATA 10
#define ONRTNL1MARKETDATA 11
#define ONRTNFUTUREMARKETDATA 12
#define ONRTNL2MARKETDATA 13
#define ONRTNL2INDEXMARKETDATA 14
#define ONRTNL2ORDER 15
#define ONRTNL2TRADE 16


///-------------------------------------------------------------------------------------
///C++ SPI�Ļص���������ʵ��
///-------------------------------------------------------------------------------------

//API�ļ̳�ʵ��
class MdApi : public CSecurityDntL2MDUserSpi
{
private:
	CSecurityDntL2MDUserApi* api;				//API����
	thread task_thread;					//�����߳�ָ�루��python���������ݣ�
	TaskQueue task_queue;			    //�������
	bool active = false;				//����״̬

public:
	MdApi()
	{
	};

	~MdApi()
	{
		if (this->active)
		{
			this->exit();
		}
	};

	//-------------------------------------------------------------------------------------
	//API�ص�����
	//-------------------------------------------------------------------------------------

	// ����ǰ�û���Ӧ
	virtual void OnFrontConnected(const CSecurityDntRspInfoField& reply);

	// ������Ȩ����Ӧ��
	virtual void OnRspSubFutureMarketData(const CSecurityDntRspInfoField& reply);

	// ȡ��������Ȩ����Ӧ��
	virtual void OnRspUnSubFutureMarketData(const CSecurityDntRspInfoField& reply);

	// ����L2����Ӧ��
	virtual void OnRspSubL2MarketData(const CSecurityDntRspInfoField& reply);

	// ȡ������Level2����Ӧ��
	virtual void OnRspUnSubL2MarketData(const CSecurityDntRspInfoField& reply);

	// ����L1����Ӧ��
	virtual void OnRspSubL1MarketData(const CSecurityDntRspInfoField& reply);

	// ȡ������Level1����Ӧ��
	virtual void OnRspUnSubL1MarketData(const CSecurityDntRspInfoField& reply);

	//��ʶ���Ӧ��
	virtual void OnRspSubL2OrderAndTrade(const CSecurityDntRspInfoField& reply);

	//ȡ����ʶ���Ӧ��
	virtual void OnRspUnSubL2OrderAndTrade(const CSecurityDntRspInfoField& reply);

	//ָ������Ӧ��
	virtual void OnRspSubL2IndexMarketData(const CSecurityDntRspInfoField& reply);

	//ȡ��ָ������Ӧ��
	virtual void OnRspUnSubL2IndexMarketData(const CSecurityDntRspInfoField& reply);

	// Level1����֪ͨ
	virtual void OnRtnL1MarketData(const CSecurityDntMarketDataField& reply);

	// ��Ȩ����֪ͨ
	virtual void OnRtnFutureMarketData(const CSecurityDntMarketDataField& reply);

	// Level2����֪ͨ
	virtual void OnRtnL2MarketData(const CSecurityDntMarketDataField& reply);

	// Level2ָ��֪ͨ
	virtual void OnRtnL2IndexMarketData(const CSecurityDntL2IndexField& reply);

	// Level2���ί������֪ͨ
	virtual void OnRtnL2Order(const CSecurityDntL2OrderField& pL2Order);

	// Level2��ʳɽ�����֪ͨ
	virtual void OnRtnL2Trade(const CSecurityDntL2TradeField& pL2Trade);

    //-------------------------------------------------------------------------------------
    //task������
    //-------------------------------------------------------------------------------------

	void processTask();

	void processFrontConnected(Task *task);

	void processRspSubFutureMarketData(Task *task);

	void processRspUnSubFutureMarketData(Task *task);

	void processRspSubL2MarketData(Task *task);

	void processRspUnSubL2MarketData(Task *task);

	void processRspSubL1MarketData(Task *task);

	void processRspUnSubL1MarketData(Task *task);

	void processRspSubL2OrderAndTrade(Task *task);

	void processRspUnSubL2OrderAndTrade(Task *task);

	void processRspSubL2IndexMarketData(Task *task);

	void processRspUnSubL2IndexMarketData(Task *task);

	void processRtnL1MarketData(Task *task);

	void processRtnFutureMarketData(Task *task);

	void processRtnL2MarketData(Task *task);

	void processRtnL2IndexMarketData(Task *task);

	void processRtnL2Order(Task *task);

	void processRtnL2Trade(Task *task);

	//-------------------------------------------------------------------------------------
    //data���ص������������ֵ�
    //error���ص������Ĵ����ֵ�
    //id������id
    //last���Ƿ�Ϊ��󷵻�
    //i������
    //-------------------------------------------------------------------------------------

	virtual void onFrontConnected(const dict &data) {};

	virtual void onRspSubFutureMarketData(const dict &data) {};

	virtual void onRspUnSubFutureMarketData(const dict &data) {};

	virtual void onRspSubL2MarketData(const dict &data) {};

	virtual void onRspUnSubL2MarketData(const dict &data) {};

	virtual void onRspSubL1MarketData(const dict &data) {};

	virtual void onRspUnSubL1MarketData(const dict &data) {};

	virtual void onRspSubL2OrderAndTrade(const dict &data) {};

	virtual void onRspUnSubL2OrderAndTrade(const dict &data) {};

	virtual void onRspSubL2IndexMarketData(const dict &data) {};

	virtual void onRspUnSubL2IndexMarketData(const dict &data) {};

	virtual void onRtnL1MarketData(const dict &data) {};

	virtual void onRtnFutureMarketData(const dict &data) {};

	virtual void onRtnL2MarketData(const dict &data) {};

	virtual void onRtnL2IndexMarketData(const dict &data) {};

	virtual void onRtnL2Order(const dict &data) {};

	virtual void onRtnL2Trade(const dict &data) {};

	//-------------------------------------------------------------------------------------
    //req:���������������ֵ�
    //-------------------------------------------------------------------------------------

	void createCSecurityDntL2MDUserApi();

	void release();

	void init();

	int join();

	int exit();

	void registerFront(string kConnectorAddress, string kDomainServer, string kContextName);

	string getTradingDay();

	int SubscribeFutureMarketData(const dict &req, bool bAll);

	int UnSubscribeFutureMarketData(const dict &req, bool bAll);

	int SubscribeL1MarketData(const dict &req, bool bAll);

	int UnSubscribeL1MarketData(const dict &req, bool bAll);

	int SubscribeL2MarketData(const dict &req, bool bAll);

	int UnSubscribeL2MarketData(const dict &req, bool bAll);

	int SubscribeL2OrderAndTrade();

	int UnSubscribeL2OrderAndTrade();

	int SubscribeL2IndexMarketData();

	int UnSubscribeL2IndexMarketData();

};