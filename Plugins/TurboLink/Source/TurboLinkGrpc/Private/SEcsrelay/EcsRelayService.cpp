//Generated by TurboLink CodeGenerator, do not edit!
#include "SEcsrelay/EcsRelayService.h"
#include "SEcsrelay/EcsRelayClient.h"
#include "EcsRelayService_Private.h"
#include "EcsRelayMarshaling.h"
#include "TurboLinkGrpcManager_Private.h"
#include "TurboLinkGrpcUtilities.h"

UECSRelayService::UECSRelayService()
	: d(new UECSRelayService::Private())
{
}

UECSRelayService::~UECSRelayService()
{
	delete d;
}

void UECSRelayService::Connect()
{
	FString serviceEndPoint = UTurboLinkGrpcUtilities::GetTurboLinkGrpcConfig()->GetServiceEndPoint(TEXT("ECSRelayService"));
	UE_LOG(LogTurboLink, Warning, TEXT("Connect to ECSRelayService: '%s'"), *serviceEndPoint);

	if (d->Channel == nullptr) {
		d->Channel = TurboLinkManager->d->CreateServiceChannel(TCHAR_TO_UTF8(*serviceEndPoint), this);
	}
	if (d->Stub == nullptr) {
		d->Stub = ecsrelay::ECSRelayService::NewStub(d->Channel->RpcChannel);
	}

	grpc_connectivity_state currentChannelState = d->Channel->RpcChannel->GetState(true);
	if (OnServiceStateChanged.IsBound())
	{
		OnServiceStateChanged.Broadcast(UTurboLinkGrpcManager::Private::GrpcStateToServiceState(currentChannelState));
	}
}

EGrpcServiceState UECSRelayService::GetServiceState() const
{
	if (d->Channel == nullptr) return EGrpcServiceState::NotCreate;

	auto rpcChannelState = d->Channel->RpcChannel->GetState(false);
	return UTurboLinkGrpcManager::Private::GrpcStateToServiceState(rpcChannelState);
}

UECSRelayServiceClient* UECSRelayService::MakeClient()
{
	auto client = UGrpcService::MakeClient<UECSRelayServiceClient>();
	return client;
}

void UECSRelayService::Shutdown()
{
	Super::Shutdown();
	d->Stub = nullptr;
	if (d->Channel != nullptr) {
		TurboLinkManager->d->RemoveServiceChannel(d->Channel, this);
		d->Channel = nullptr;
	}
}

void UECSRelayService::CallAuthenticate(const FGrpcEcsrelaySignature& Request, FAuthenticateLambda Lambda)
{
	if (InnerClient == nullptr)
	{
		InnerClient = MakeClient();
	}
	UECSRelayServiceAuthenticateLambdaWrapper* lambdaWrapper = NewObject<UECSRelayServiceAuthenticateLambdaWrapper>();
	lambdaWrapper->InnerClient = InnerClient;
	lambdaWrapper->Lambda = Lambda;
	lambdaWrapper->Handle = InnerClient->InitAuthenticate();
	InnerClient->OnAuthenticateResponse.AddUniqueDynamic(lambdaWrapper, &UECSRelayServiceAuthenticateLambdaWrapper::OnResponse);
	InnerClient->Authenticate(lambdaWrapper->Handle, Request);
}

void UECSRelayService::CallRevoke(const FGrpcEcsrelaySignature& Request, FRevokeLambda Lambda)
{
	if (InnerClient == nullptr)
	{
		InnerClient = MakeClient();
	}
	UECSRelayServiceRevokeLambdaWrapper* lambdaWrapper = NewObject<UECSRelayServiceRevokeLambdaWrapper>();
	lambdaWrapper->InnerClient = InnerClient;
	lambdaWrapper->Lambda = Lambda;
	lambdaWrapper->Handle = InnerClient->InitRevoke();
	InnerClient->OnRevokeResponse.AddUniqueDynamic(lambdaWrapper, &UECSRelayServiceRevokeLambdaWrapper::OnResponse);
	InnerClient->Revoke(lambdaWrapper->Handle, Request);
}

void UECSRelayService::CallPing(const FGrpcEcsrelaySignature& Request, FPingLambda Lambda)
{
	if (InnerClient == nullptr)
	{
		InnerClient = MakeClient();
	}
	UECSRelayServicePingLambdaWrapper* lambdaWrapper = NewObject<UECSRelayServicePingLambdaWrapper>();
	lambdaWrapper->InnerClient = InnerClient;
	lambdaWrapper->Lambda = Lambda;
	lambdaWrapper->Handle = InnerClient->InitPing();
	InnerClient->OnPingResponse.AddUniqueDynamic(lambdaWrapper, &UECSRelayServicePingLambdaWrapper::OnResponse);
	InnerClient->Ping(lambdaWrapper->Handle, Request);
}

void UECSRelayService::CallCountAuthenticated(const FGrpcEcsrelayCountIdentitiesRequest& Request, FCountAuthenticatedLambda Lambda)
{
	if (InnerClient == nullptr)
	{
		InnerClient = MakeClient();
	}
	UECSRelayServiceCountAuthenticatedLambdaWrapper* lambdaWrapper = NewObject<UECSRelayServiceCountAuthenticatedLambdaWrapper>();
	lambdaWrapper->InnerClient = InnerClient;
	lambdaWrapper->Lambda = Lambda;
	lambdaWrapper->Handle = InnerClient->InitCountAuthenticated();
	InnerClient->OnCountAuthenticatedResponse.AddUniqueDynamic(lambdaWrapper, &UECSRelayServiceCountAuthenticatedLambdaWrapper::OnResponse);
	InnerClient->CountAuthenticated(lambdaWrapper->Handle, Request);
}

void UECSRelayService::CallCountConnected(const FGrpcEcsrelayCountIdentitiesRequest& Request, FCountConnectedLambda Lambda)
{
	if (InnerClient == nullptr)
	{
		InnerClient = MakeClient();
	}
	UECSRelayServiceCountConnectedLambdaWrapper* lambdaWrapper = NewObject<UECSRelayServiceCountConnectedLambdaWrapper>();
	lambdaWrapper->InnerClient = InnerClient;
	lambdaWrapper->Lambda = Lambda;
	lambdaWrapper->Handle = InnerClient->InitCountConnected();
	InnerClient->OnCountConnectedResponse.AddUniqueDynamic(lambdaWrapper, &UECSRelayServiceCountConnectedLambdaWrapper::OnResponse);
	InnerClient->CountConnected(lambdaWrapper->Handle, Request);
}

void UECSRelayService::CallSubscribe(const FGrpcEcsrelaySubscriptionRequest& Request, FSubscribeLambda Lambda)
{
	if (InnerClient == nullptr)
	{
		InnerClient = MakeClient();
	}
	UECSRelayServiceSubscribeLambdaWrapper* lambdaWrapper = NewObject<UECSRelayServiceSubscribeLambdaWrapper>();
	lambdaWrapper->InnerClient = InnerClient;
	lambdaWrapper->Lambda = Lambda;
	lambdaWrapper->Handle = InnerClient->InitSubscribe();
	InnerClient->OnSubscribeResponse.AddUniqueDynamic(lambdaWrapper, &UECSRelayServiceSubscribeLambdaWrapper::OnResponse);
	InnerClient->Subscribe(lambdaWrapper->Handle, Request);
}

void UECSRelayService::CallUnsubscribe(const FGrpcEcsrelaySubscriptionRequest& Request, FUnsubscribeLambda Lambda)
{
	if (InnerClient == nullptr)
	{
		InnerClient = MakeClient();
	}
	UECSRelayServiceUnsubscribeLambdaWrapper* lambdaWrapper = NewObject<UECSRelayServiceUnsubscribeLambdaWrapper>();
	lambdaWrapper->InnerClient = InnerClient;
	lambdaWrapper->Lambda = Lambda;
	lambdaWrapper->Handle = InnerClient->InitUnsubscribe();
	InnerClient->OnUnsubscribeResponse.AddUniqueDynamic(lambdaWrapper, &UECSRelayServiceUnsubscribeLambdaWrapper::OnResponse);
	InnerClient->Unsubscribe(lambdaWrapper->Handle, Request);
}

void UECSRelayService::CallOpenStream(const FGrpcEcsrelaySignature& Request, FOpenStreamLambda Lambda)
{
	if (InnerClient == nullptr)
	{
		InnerClient = MakeClient();
	}
	UECSRelayServiceOpenStreamLambdaWrapper* lambdaWrapper = NewObject<UECSRelayServiceOpenStreamLambdaWrapper>();
	lambdaWrapper->InnerClient = InnerClient;
	lambdaWrapper->Lambda = Lambda;
	lambdaWrapper->Handle = InnerClient->InitOpenStream();
	InnerClient->OnOpenStreamResponse.AddUniqueDynamic(lambdaWrapper, &UECSRelayServiceOpenStreamLambdaWrapper::OnResponse);
	InnerClient->OnContextStateChange.AddUniqueDynamic(lambdaWrapper, &UECSRelayServiceOpenStreamLambdaWrapper::OnContextStateChanged);
	InnerClient->OpenStream(lambdaWrapper->Handle, Request);
}

void UECSRelayService::CallPush(const FGrpcEcsrelayPushRequest& Request, FPushLambda Lambda)
{
	if (InnerClient == nullptr)
	{
		InnerClient = MakeClient();
	}
	UECSRelayServicePushLambdaWrapper* lambdaWrapper = NewObject<UECSRelayServicePushLambdaWrapper>();
	lambdaWrapper->InnerClient = InnerClient;
	lambdaWrapper->Lambda = Lambda;
	lambdaWrapper->Handle = InnerClient->InitPush();
	InnerClient->OnPushResponse.AddUniqueDynamic(lambdaWrapper, &UECSRelayServicePushLambdaWrapper::OnResponse);
	InnerClient->Push(lambdaWrapper->Handle, Request);
}

void UECSRelayService::CallMinBalanceForPush(const FGrpcEcsrelayBalanceRequest& Request, FMinBalanceForPushLambda Lambda)
{
	if (InnerClient == nullptr)
	{
		InnerClient = MakeClient();
	}
	UECSRelayServiceMinBalanceForPushLambdaWrapper* lambdaWrapper = NewObject<UECSRelayServiceMinBalanceForPushLambdaWrapper>();
	lambdaWrapper->InnerClient = InnerClient;
	lambdaWrapper->Lambda = Lambda;
	lambdaWrapper->Handle = InnerClient->InitMinBalanceForPush();
	InnerClient->OnMinBalanceForPushResponse.AddUniqueDynamic(lambdaWrapper, &UECSRelayServiceMinBalanceForPushLambdaWrapper::OnResponse);
	InnerClient->MinBalanceForPush(lambdaWrapper->Handle, Request);
}
