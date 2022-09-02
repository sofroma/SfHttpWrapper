// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Http.h"
#include "SfHttpRequest.generated.h"

DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnRequestComplete, bool, Success, int32, ResponseCode, FString, Content);

/**
 * 
 */
UCLASS()
class SFHTTPWRAPPER_API USfHttpRequest : public UObject
{
	GENERATED_BODY()

private:
	FOnRequestComplete Callback;
	FString Method;
	FString RequestBody;
	FString ContentType;
	TMap<FString, FString> Headers;

public:
	void Send(FString Url);
	void SetCallback(FOnRequestComplete Callback);
	void SetMethod(FString Method);
	void SetContent(FString Content);
	void SetHeaders(TMap<FString, FString> Headers);
	void SetContentType(FString ContentType);
	void OnRequestComplete(FHttpRequestPtr Request, FHttpResponsePtr Response, bool Success);
};
