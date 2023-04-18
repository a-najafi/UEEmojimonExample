//Generated by TurboLink CodeGenerator, do not edit!
#include "SGreeter/GreeterClient.h"
#include "SGreeter/GreeterService.h"
#include "GreeterContext.h"
#include "TurboLinkGrpcManager_Private.h"
#include "Templates/SharedPointer.h"

FGrpcContextHandle UGreeterServiceClient::InitHello()
{
	FGrpcContextHandle handle = Service->TurboLinkManager->GetNextContextHandle();
	auto context = UGrpcClient::MakeContext<GrpcContext_GreeterService_Hello>(handle);
	context->RpcContext = UTurboLinkGrpcManager::Private::CreateRpcClientContext();
	return context->GetHandle();
}

void UGreeterServiceClient::Hello(FGrpcContextHandle Handle, const FGrpcGreeterHelloRequest& Request)
{
	auto context = UGrpcClient::GetContext(Handle);
	if (context != nullptr)
	{
		auto contextHello = StaticCastSharedPtr<GrpcContext_GreeterService_Hello>(*context);
		contextHello->Call(Request);
	}
}
void UGreeterServiceClient::TryCancel(FGrpcContextHandle Handle)
{
	auto context = UGrpcClient::GetContext(Handle);
	if (context != nullptr)
	{
		(*context)->TryCancel();
	}
}

void UGreeterServiceClient::Shutdown()
{
	OnHelloResponse.Clear();
	Super::Shutdown();
}
FGrpcContextHandle UTimeServiceClient::InitTicktok()
{
	FGrpcContextHandle handle = Service->TurboLinkManager->GetNextContextHandle();
	auto context = UGrpcClient::MakeContext<GrpcContext_TimeService_Ticktok>(handle);
	context->RpcContext = UTurboLinkGrpcManager::Private::CreateRpcClientContext();
	return context->GetHandle();
}

void UTimeServiceClient::Ticktok(FGrpcContextHandle Handle, const FGrpcGreeterTicktokRequest& Request)
{
	auto context = UGrpcClient::GetContext(Handle);
	if (context != nullptr)
	{
		auto contextTicktok = StaticCastSharedPtr<GrpcContext_TimeService_Ticktok>(*context);
		contextTicktok->Call(Request);
	}
}
FGrpcContextHandle UTimeServiceClient::InitWatch()
{
	FGrpcContextHandle handle = Service->TurboLinkManager->GetNextContextHandle();
	auto context = UGrpcClient::MakeContext<GrpcContext_TimeService_Watch>(handle);
	context->RpcContext = UTurboLinkGrpcManager::Private::CreateRpcClientContext();
	context->Init();
	return context->GetHandle();
}

void UTimeServiceClient::Watch(FGrpcContextHandle Handle, const FGrpcGreeterWatchRequest& Request)
{
	auto context = UGrpcClient::GetContext(Handle);
	if (context != nullptr)
	{
		auto contextWatch = StaticCastSharedPtr<GrpcContext_TimeService_Watch>(*context);
		contextWatch->Call(Request);
	}
}
void UTimeServiceClient::TryCancel(FGrpcContextHandle Handle)
{
	auto context = UGrpcClient::GetContext(Handle);
	if (context != nullptr)
	{
		(*context)->TryCancel();
	}
}

void UTimeServiceClient::Shutdown()
{
	OnTicktokResponse.Clear();
	OnWatchResponse.Clear();
	Super::Shutdown();
}