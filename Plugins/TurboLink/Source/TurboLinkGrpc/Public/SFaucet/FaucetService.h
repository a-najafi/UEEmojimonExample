//Generated by TurboLink CodeGenerator, do not edit!
#pragma once
#include "TurboLinkGrpcService.h"
#include "SFaucet/FaucetClient.h"
#include "FaucetService.generated.h"

class UTurboLinkGrpcManager;

UCLASS(ClassGroup = TurboLink, BlueprintType)
class TURBOLINKGRPC_API UFaucetService : public UGrpcService
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable)
	virtual void Connect() override;
	
	UFUNCTION(BlueprintCallable)
	virtual EGrpcServiceState GetServiceState() const override;

	UFUNCTION(BlueprintCallable)
	UFaucetServiceClient* MakeClient();

private:
	virtual void Shutdown() override;

	UPROPERTY()
	UFaucetServiceClient* InnerClient; 
public:
	typedef TFunction<void(const FGrpcResult& Result, const FGrpcFaucetDripResponse& Response)> FDripLambda;
	void CallDrip(const FGrpcFaucetDripRequest& Request, FDripLambda Lambda);

	typedef TFunction<void(const FGrpcResult& Result, const FGrpcFaucetDripResponse& Response)> FDripDevLambda;
	void CallDripDev(const FGrpcFaucetDripDevRequest& Request, FDripDevLambda Lambda);

	typedef TFunction<void(const FGrpcResult& Result, const FGrpcFaucetDripResponse& Response)> FDripVerifyTweetLambda;
	void CallDripVerifyTweet(const FGrpcFaucetDripRequest& Request, FDripVerifyTweetLambda Lambda);

	typedef TFunction<void(const FGrpcResult& Result, const FGrpcFaucetTimeUntilDripResponse& Response)> FTimeUntilDripLambda;
	void CallTimeUntilDrip(const FGrpcFaucetDripRequest& Request, FTimeUntilDripLambda Lambda);

	typedef TFunction<void(const FGrpcResult& Result, const FGrpcFaucetGetLinkedTwittersResponse& Response)> FGetLinkedTwittersLambda;
	void CallGetLinkedTwitters(const FGrpcFaucetGetLinkedTwittersRequest& Request, FGetLinkedTwittersLambda Lambda);

	typedef TFunction<void(const FGrpcResult& Result, const FGrpcFaucetLinkedTwitterForAddressResponse& Response)> FGetLinkedTwitterForAddressLambda;
	void CallGetLinkedTwitterForAddress(const FGrpcFaucetLinkedTwitterForAddressRequest& Request, FGetLinkedTwitterForAddressLambda Lambda);

	typedef TFunction<void(const FGrpcResult& Result, const FGrpcFaucetLinkedAddressForTwitterResponse& Response)> FGetLinkedAddressForTwitterLambda;
	void CallGetLinkedAddressForTwitter(const FGrpcFaucetLinkedAddressForTwitterRequest& Request, FGetLinkedAddressForTwitterLambda Lambda);

	typedef TFunction<void(const FGrpcResult& Result, const FGrpcFaucetSetLinkedTwitterResponse& Response)> FSetLinkedTwitterLambda;
	void CallSetLinkedTwitter(const FGrpcFaucetSetLinkedTwitterRequest& Request, FSetLinkedTwitterLambda Lambda);

public:
	class Private;
	Private* const d = nullptr;

public:
	UFaucetService();
	virtual ~UFaucetService();
};

