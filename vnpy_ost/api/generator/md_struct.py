CSecurityDntSubscribeReq = {
    "securitySource": "uint16_t",
    "securityId": "string",
    "subscribeType": "enum",
}

CSecurityDntRspInfoField = {
    "ErrorID": "int32_t",
    "ErrorMsg": "string",
}

EntryInfo = {
    "level": "uint16_t",
    "price": "int64_t",
    "OrderQty": "int64_t",
}

CSecurityDntMarketDataField = {
    "origTime": "int64_t",
    "channelNo": "uint16_t",
    "marketId": "uint16_t",
    "MDStreamId": "enum",
    "MDStreamType": "enum",
    "securityId": "string",
    "preClosePx": "int64_t",
    "openPx": "int64_t",
    "closePx": "int64_t",
    "lastPx": "int64_t",
    "highPx": "int64_t",
    "lowPx": "int64_t",
    "upperLimit": "int64_t",
    "lowerLimit": "int64_t",
    "tradingPhase": "char",
    "tradeNums": "int64_t",
    "tradeVolumn": "int64_t",
    "tradeValue": "int64_t",
    "buyLength": "uint16_t",
    "buyEntry": "dict",
    "sellLength": "uint16_t",
    "sellEntry": "dict",
}

CSecurityDntL2TradeField = {
    "ChannelNo": "uint16_t",
    "marketId": "uint16_t",
    "ApplSeqNum": "int64_t",
    "MDStreamID": "enum",
    "BidApplSeqNum": "int64_t",
    "OfferApplSeqNum": "int64_t",
    "SecurityID": "string",
    "SecurityIDSource": "string",
    "LastPrice": "int64_t",
    "LastQty": "int64_t",
    "ExecType": "char",
    "TransactTime": "int64_t",
}

CSecurityDntL2OrderField = {
    "ChannelNo": "uint16_t",
    "marketId": "uint16_t",
    "ApplSeqNum": "int64_t",
    "MDStreamID": "enum",
    "SecurityID": "string",
    "SecurityIDSource": "string",
    "Price": "int64_t",
    "OrderQty": "int64_t",
    "Side": "char",
    "TransactTime": "int64_t",
    "OrderType": "char",
}

CSecurityDntL2IndexField = {
    "timeStamp": "int64_t",
    "marketId": "uint16_t",
    "SecurityID": "string",
    "preCloseIndex": "int64_t",
    "openIndex": "int64_t",
    "closeIndex": "int64_t",
    "highIndex": "int64_t",
    "lowIndex": "int64_t",
    "lastIndex": "int64_t",
    "turnOver": "int64_t",
    "totalVolume": "int64_t",
}
