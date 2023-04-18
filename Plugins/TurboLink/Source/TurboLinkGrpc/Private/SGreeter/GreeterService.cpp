//Generated by TurboLink CodeGenerator, do not edit!
#include "SGreeter/GreeterService.h"
#include "SGreeter/GreeterClient.h"
#include "GreeterService_Private.h"
#include "GreeterMarshaling.h"
#include "TurboLinkGrpcManager_Private.h"
#include "TurboLinkGrpcUtilities.h"

UGreeterService::UGreeterService()
	: d(new UGreeterService::Private())
{
}

UGreeterService::~UGreeterService()
{
	delete d;
}

void UGreeterService::Connect()
{
	FString serviceEndPoint = UTurboLinkGrpcUtilities::GetTurboLinkGrpcConfig()->GetServiceEndPoint(TEXT("GreeterService"));
	UE_LOG(LogTurboLink, Warning, TEXT("Connect to GreeterService: '%s'"), *serviceEndPoint);

	if (d->Channel == nullptr) {
		d->Channel = TurboLinkManager->d->CreateServiceChannel(TCHAR_TO_UTF8(*serviceEndPoint), this);
	}
	if (d->Stub == nullptr) {
		d->Stub = Greeter::GreeterService::NewStub(d->Channel->RpcChannel);
	}

	grpc_connectivity_state currentChannelState = d->Channel->RpcChannel->GetState(true);
	if (OnServiceStateChanged.IsBound())
	{
		OnServiceStateChanged.Broadcast(UTurboLinkGrpcManager::Private::GrpcStateToServiceState(currentChannelState));
	}
}

EGrpcServiceState UGreeterService::GetServiceState() const
{
	if (d->Channel == nullptr) return EGrpcServiceState::NotCreate;

	auto rpcChannelState = d->Channel->RpcChannel->GetState(false);
	return UTurboLinkGrpcManager::Private::GrpcStateToServiceState(rpcChannelState);
}

UGreeterServiceClient* UGreeterService::MakeClient()
{
	auto client = UGrpcService::MakeClient<UGreeterServiceClient>();
	return client;
}

void UGreeterService::Shutdown()
{
	Super::Shutdown();
	d->Stub = nullptr;
	if (d->Channel != nullptr) {
		TurboLinkManager->d->RemoveServiceChannel(d->Channel, this);
		d->Channel = nullptr;
	}
}

void UGreeterService::CallHello(const FGrpcGreeterHelloRequest& Request, FHelloLambda Lambda)
{
	if (InnerClient == nullptr)
	{
		InnerClient = MakeClient();
	}
	UGreeterServiceHelloLambdaWrapper* lambdaWrapper = NewObject<UGreeterServiceHelloLambdaWrapper>();
	lambdaWrapper->InnerClient = InnerClient;
	lambdaWrapper->Lambda = Lambda;
	lambdaWrapper->Handle = InnerClient->InitHello();
	InnerClient->OnHelloResponse.AddUniqueDynamic(lambdaWrapper, &UGreeterServiceHelloLambdaWrapper::OnResponse);
	InnerClient->Hello(lambdaWrapper->Handle, Request);
}

UTimeService::UTimeService()
	: d(new UTimeService::Private())
{
}

UTimeService::~UTimeService()
{
	delete d;
}

void UTimeService::Connect()
{
	FString serviceEndPoint = UTurboLinkGrpcUtilities::GetTurboLinkGrpcConfig()->GetServiceEndPoint(TEXT("TimeService"));
	UE_LOG(LogTurboLink, Warning, TEXT("Connect to TimeService: '%s'"), *serviceEndPoint);

	if (d->Channel == nullptr) {
		d->Channel = TurboLinkManager->d->CreateServiceChannel(TCHAR_TO_UTF8(*serviceEndPoint), this);
	}
	if (d->Stub == nullptr) {
		d->Stub = Greeter::TimeService::NewStub(d->Channel->RpcChannel);
	}

	grpc_connectivity_state currentChannelState = d->Channel->RpcChannel->GetState(true);
	if (OnServiceStateChanged.IsBound())
	{
		OnServiceStateChanged.Broadcast(UTurboLinkGrpcManager::Private::GrpcStateToServiceState(currentChannelState));
	}
}

EGrpcServiceState UTimeService::GetServiceState() const
{
	if (d->Channel == nullptr) return EGrpcServiceState::NotCreate;

	auto rpcChannelState = d->Channel->RpcChannel->GetState(false);
	return UTurboLinkGrpcManager::Private::GrpcStateToServiceState(rpcChannelState);
}

UTimeServiceClient* UTimeService::MakeClient()
{
	auto client = UGrpcService::MakeClient<UTimeServiceClient>();
	return client;
}

void UTimeService::Shutdown()
{
	Super::Shutdown();
	d->Stub = nullptr;
	if (d->Channel != nullptr) {
		TurboLinkManager->d->RemoveServiceChannel(d->Channel, this);
		d->Channel = nullptr;
	}
}

void UTimeService::CallTicktok(const FGrpcGreeterTicktokRequest& Request, FTicktokLambda Lambda)
{
	if (InnerClient == nullptr)
	{
		InnerClient = MakeClient();
	}
	UTimeServiceTicktokLambdaWrapper* lambdaWrapper = NewObject<UTimeServiceTicktokLambdaWrapper>();
	lambdaWrapper->InnerClient = InnerClient;
	lambdaWrapper->Lambda = Lambda;
	lambdaWrapper->Handle = InnerClient->InitTicktok();
	InnerClient->OnTicktokResponse.AddUniqueDynamic(lambdaWrapper, &UTimeServiceTicktokLambdaWrapper::OnResponse);
	InnerClient->OnContextStateChange.AddUniqueDynamic(lambdaWrapper, &UTimeServiceTicktokLambdaWrapper::OnContextStateChanged);
	InnerClient->Ticktok(lambdaWrapper->Handle, Request);
}
