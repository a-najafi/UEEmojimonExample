//Generated by TurboLink CodeGenerator, do not edit!
#include "FaucetContext.h"
#include "SFaucet/FaucetClient.h"
#include "FaucetService_Private.h"
#include "FaucetMarshaling.h"
#include "TurboLinkGrpcManager.h"

GrpcContext_FaucetService_Drip::GrpcContext_FaucetService_Drip(FGrpcContextHandle _Handle, UGrpcService* _Service, UGrpcClient* _Client)
	: Super(_Handle, _Service, _Client)
{
}

void GrpcContext_FaucetService_Drip::Call(const FGrpcFaucetDripRequest& Request)
{
	check(GetState() == EGrpcContextState::Ready);
	UpdateState(EGrpcContextState::Initialing);

	::faucet::DripRequest rpcRequest;
	TURBOLINK_TO_GRPC(&Request, &rpcRequest);

	UFaucetService* service = (UFaucetService*)Service;
	RpcReaderWriter = service->d->Stub->AsyncDrip(RpcContext.get(), rpcRequest, service->TurboLinkManager->d->CompletionQueue.get());
	RpcReaderWriter->ReadInitialMetadata(InitialTag);
}

void GrpcContext_FaucetService_Drip::OnRpcEvent(bool Ok, const void* EventTag)
{
	Super::OnRpcEventInternal(Ok, EventTag, [this](const FGrpcResult& _Result, ::faucet::DripResponse* _RpcResponse) {
		UFaucetServiceClient* client = (UFaucetServiceClient*)(this->Client);
		if (!(client->OnDripResponse.IsBound())) return;

		FGrpcFaucetDripResponse response;
		if (_RpcResponse) {
			GRPC_TO_TURBOLINK(_RpcResponse, &response);
		}
		client->OnDripResponse.Broadcast(Handle, _Result, response);
	});
}

GrpcContext_FaucetService_DripDev::GrpcContext_FaucetService_DripDev(FGrpcContextHandle _Handle, UGrpcService* _Service, UGrpcClient* _Client)
	: Super(_Handle, _Service, _Client)
{
}

void GrpcContext_FaucetService_DripDev::Call(const FGrpcFaucetDripDevRequest& Request)
{
	check(GetState() == EGrpcContextState::Ready);
	UpdateState(EGrpcContextState::Initialing);

	::faucet::DripDevRequest rpcRequest;
	TURBOLINK_TO_GRPC(&Request, &rpcRequest);

	UFaucetService* service = (UFaucetService*)Service;
	RpcReaderWriter = service->d->Stub->AsyncDripDev(RpcContext.get(), rpcRequest, service->TurboLinkManager->d->CompletionQueue.get());
	RpcReaderWriter->ReadInitialMetadata(InitialTag);
}

void GrpcContext_FaucetService_DripDev::OnRpcEvent(bool Ok, const void* EventTag)
{
	Super::OnRpcEventInternal(Ok, EventTag, [this](const FGrpcResult& _Result, ::faucet::DripResponse* _RpcResponse) {
		UFaucetServiceClient* client = (UFaucetServiceClient*)(this->Client);
		if (!(client->OnDripDevResponse.IsBound())) return;

		FGrpcFaucetDripResponse response;
		if (_RpcResponse) {
			GRPC_TO_TURBOLINK(_RpcResponse, &response);
		}
		client->OnDripDevResponse.Broadcast(Handle, _Result, response);
	});
}

GrpcContext_FaucetService_DripVerifyTweet::GrpcContext_FaucetService_DripVerifyTweet(FGrpcContextHandle _Handle, UGrpcService* _Service, UGrpcClient* _Client)
	: Super(_Handle, _Service, _Client)
{
}

void GrpcContext_FaucetService_DripVerifyTweet::Call(const FGrpcFaucetDripRequest& Request)
{
	check(GetState() == EGrpcContextState::Ready);
	UpdateState(EGrpcContextState::Initialing);

	::faucet::DripRequest rpcRequest;
	TURBOLINK_TO_GRPC(&Request, &rpcRequest);

	UFaucetService* service = (UFaucetService*)Service;
	RpcReaderWriter = service->d->Stub->AsyncDripVerifyTweet(RpcContext.get(), rpcRequest, service->TurboLinkManager->d->CompletionQueue.get());
	RpcReaderWriter->ReadInitialMetadata(InitialTag);
}

void GrpcContext_FaucetService_DripVerifyTweet::OnRpcEvent(bool Ok, const void* EventTag)
{
	Super::OnRpcEventInternal(Ok, EventTag, [this](const FGrpcResult& _Result, ::faucet::DripResponse* _RpcResponse) {
		UFaucetServiceClient* client = (UFaucetServiceClient*)(this->Client);
		if (!(client->OnDripVerifyTweetResponse.IsBound())) return;

		FGrpcFaucetDripResponse response;
		if (_RpcResponse) {
			GRPC_TO_TURBOLINK(_RpcResponse, &response);
		}
		client->OnDripVerifyTweetResponse.Broadcast(Handle, _Result, response);
	});
}

GrpcContext_FaucetService_TimeUntilDrip::GrpcContext_FaucetService_TimeUntilDrip(FGrpcContextHandle _Handle, UGrpcService* _Service, UGrpcClient* _Client)
	: Super(_Handle, _Service, _Client)
{
}

void GrpcContext_FaucetService_TimeUntilDrip::Call(const FGrpcFaucetDripRequest& Request)
{
	check(GetState() == EGrpcContextState::Ready);
	UpdateState(EGrpcContextState::Initialing);

	::faucet::DripRequest rpcRequest;
	TURBOLINK_TO_GRPC(&Request, &rpcRequest);

	UFaucetService* service = (UFaucetService*)Service;
	RpcReaderWriter = service->d->Stub->AsyncTimeUntilDrip(RpcContext.get(), rpcRequest, service->TurboLinkManager->d->CompletionQueue.get());
	RpcReaderWriter->ReadInitialMetadata(InitialTag);
}

void GrpcContext_FaucetService_TimeUntilDrip::OnRpcEvent(bool Ok, const void* EventTag)
{
	Super::OnRpcEventInternal(Ok, EventTag, [this](const FGrpcResult& _Result, ::faucet::TimeUntilDripResponse* _RpcResponse) {
		UFaucetServiceClient* client = (UFaucetServiceClient*)(this->Client);
		if (!(client->OnTimeUntilDripResponse.IsBound())) return;

		FGrpcFaucetTimeUntilDripResponse response;
		if (_RpcResponse) {
			GRPC_TO_TURBOLINK(_RpcResponse, &response);
		}
		client->OnTimeUntilDripResponse.Broadcast(Handle, _Result, response);
	});
}

GrpcContext_FaucetService_GetLinkedTwitters::GrpcContext_FaucetService_GetLinkedTwitters(FGrpcContextHandle _Handle, UGrpcService* _Service, UGrpcClient* _Client)
	: Super(_Handle, _Service, _Client)
{
}

void GrpcContext_FaucetService_GetLinkedTwitters::Call(const FGrpcFaucetGetLinkedTwittersRequest& Request)
{
	check(GetState() == EGrpcContextState::Ready);
	UpdateState(EGrpcContextState::Initialing);

	::faucet::GetLinkedTwittersRequest rpcRequest;
	TURBOLINK_TO_GRPC(&Request, &rpcRequest);

	UFaucetService* service = (UFaucetService*)Service;
	RpcReaderWriter = service->d->Stub->AsyncGetLinkedTwitters(RpcContext.get(), rpcRequest, service->TurboLinkManager->d->CompletionQueue.get());
	RpcReaderWriter->ReadInitialMetadata(InitialTag);
}

void GrpcContext_FaucetService_GetLinkedTwitters::OnRpcEvent(bool Ok, const void* EventTag)
{
	Super::OnRpcEventInternal(Ok, EventTag, [this](const FGrpcResult& _Result, ::faucet::GetLinkedTwittersResponse* _RpcResponse) {
		UFaucetServiceClient* client = (UFaucetServiceClient*)(this->Client);
		if (!(client->OnGetLinkedTwittersResponse.IsBound())) return;

		FGrpcFaucetGetLinkedTwittersResponse response;
		if (_RpcResponse) {
			GRPC_TO_TURBOLINK(_RpcResponse, &response);
		}
		client->OnGetLinkedTwittersResponse.Broadcast(Handle, _Result, response);
	});
}

GrpcContext_FaucetService_GetLinkedTwitterForAddress::GrpcContext_FaucetService_GetLinkedTwitterForAddress(FGrpcContextHandle _Handle, UGrpcService* _Service, UGrpcClient* _Client)
	: Super(_Handle, _Service, _Client)
{
}

void GrpcContext_FaucetService_GetLinkedTwitterForAddress::Call(const FGrpcFaucetLinkedTwitterForAddressRequest& Request)
{
	check(GetState() == EGrpcContextState::Ready);
	UpdateState(EGrpcContextState::Initialing);

	::faucet::LinkedTwitterForAddressRequest rpcRequest;
	TURBOLINK_TO_GRPC(&Request, &rpcRequest);

	UFaucetService* service = (UFaucetService*)Service;
	RpcReaderWriter = service->d->Stub->AsyncGetLinkedTwitterForAddress(RpcContext.get(), rpcRequest, service->TurboLinkManager->d->CompletionQueue.get());
	RpcReaderWriter->ReadInitialMetadata(InitialTag);
}

void GrpcContext_FaucetService_GetLinkedTwitterForAddress::OnRpcEvent(bool Ok, const void* EventTag)
{
	Super::OnRpcEventInternal(Ok, EventTag, [this](const FGrpcResult& _Result, ::faucet::LinkedTwitterForAddressResponse* _RpcResponse) {
		UFaucetServiceClient* client = (UFaucetServiceClient*)(this->Client);
		if (!(client->OnGetLinkedTwitterForAddressResponse.IsBound())) return;

		FGrpcFaucetLinkedTwitterForAddressResponse response;
		if (_RpcResponse) {
			GRPC_TO_TURBOLINK(_RpcResponse, &response);
		}
		client->OnGetLinkedTwitterForAddressResponse.Broadcast(Handle, _Result, response);
	});
}

GrpcContext_FaucetService_GetLinkedAddressForTwitter::GrpcContext_FaucetService_GetLinkedAddressForTwitter(FGrpcContextHandle _Handle, UGrpcService* _Service, UGrpcClient* _Client)
	: Super(_Handle, _Service, _Client)
{
}

void GrpcContext_FaucetService_GetLinkedAddressForTwitter::Call(const FGrpcFaucetLinkedAddressForTwitterRequest& Request)
{
	check(GetState() == EGrpcContextState::Ready);
	UpdateState(EGrpcContextState::Initialing);

	::faucet::LinkedAddressForTwitterRequest rpcRequest;
	TURBOLINK_TO_GRPC(&Request, &rpcRequest);

	UFaucetService* service = (UFaucetService*)Service;
	RpcReaderWriter = service->d->Stub->AsyncGetLinkedAddressForTwitter(RpcContext.get(), rpcRequest, service->TurboLinkManager->d->CompletionQueue.get());
	RpcReaderWriter->ReadInitialMetadata(InitialTag);
}

void GrpcContext_FaucetService_GetLinkedAddressForTwitter::OnRpcEvent(bool Ok, const void* EventTag)
{
	Super::OnRpcEventInternal(Ok, EventTag, [this](const FGrpcResult& _Result, ::faucet::LinkedAddressForTwitterResponse* _RpcResponse) {
		UFaucetServiceClient* client = (UFaucetServiceClient*)(this->Client);
		if (!(client->OnGetLinkedAddressForTwitterResponse.IsBound())) return;

		FGrpcFaucetLinkedAddressForTwitterResponse response;
		if (_RpcResponse) {
			GRPC_TO_TURBOLINK(_RpcResponse, &response);
		}
		client->OnGetLinkedAddressForTwitterResponse.Broadcast(Handle, _Result, response);
	});
}

GrpcContext_FaucetService_SetLinkedTwitter::GrpcContext_FaucetService_SetLinkedTwitter(FGrpcContextHandle _Handle, UGrpcService* _Service, UGrpcClient* _Client)
	: Super(_Handle, _Service, _Client)
{
}

void GrpcContext_FaucetService_SetLinkedTwitter::Call(const FGrpcFaucetSetLinkedTwitterRequest& Request)
{
	check(GetState() == EGrpcContextState::Ready);
	UpdateState(EGrpcContextState::Initialing);

	::faucet::SetLinkedTwitterRequest rpcRequest;
	TURBOLINK_TO_GRPC(&Request, &rpcRequest);

	UFaucetService* service = (UFaucetService*)Service;
	RpcReaderWriter = service->d->Stub->AsyncSetLinkedTwitter(RpcContext.get(), rpcRequest, service->TurboLinkManager->d->CompletionQueue.get());
	RpcReaderWriter->ReadInitialMetadata(InitialTag);
}

void GrpcContext_FaucetService_SetLinkedTwitter::OnRpcEvent(bool Ok, const void* EventTag)
{
	Super::OnRpcEventInternal(Ok, EventTag, [this](const FGrpcResult& _Result, ::faucet::SetLinkedTwitterResponse* _RpcResponse) {
		UFaucetServiceClient* client = (UFaucetServiceClient*)(this->Client);
		if (!(client->OnSetLinkedTwitterResponse.IsBound())) return;

		FGrpcFaucetSetLinkedTwitterResponse response;
		if (_RpcResponse) {
			GRPC_TO_TURBOLINK(_RpcResponse, &response);
		}
		client->OnSetLinkedTwitterResponse.Broadcast(Handle, _Result, response);
	});
}