// Fill out your copyright notice in the Description page of Project Settings.


#include "SfHttpComponent.h"

// Sets default values for this component's properties
USfHttpComponent::USfHttpComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void USfHttpComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void USfHttpComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void USfHttpComponent::SendHttpRequest(FString Url, const FOnRequestComplete& Callback)
{
	USfHttpRequest* Request = NewObject<USfHttpRequest>();
	Request->SetCallback(Callback);
	Request->SetMethod("GET");
	Request->Send(Url);
}

void USfHttpComponent::SendHttpRequestWithHeaders(FString Url, TMap<FString, FString> Headers, const FOnRequestComplete& Callback)
{
	USfHttpRequest* Request = NewObject<USfHttpRequest>();
	Request->SetCallback(Callback);
	Request->SetMethod("GET");
	Request->SetHeaders(Headers);
	Request->Send(Url);
}

// When we send POST request, Content-Type is required by Unreal Engine
void USfHttpComponent::SendHttpPostRequest(FString Url, FString ContentType, FString Content, const FOnRequestComplete& Callback)
{
	USfHttpRequest* Request = NewObject<USfHttpRequest>();
	Request->SetCallback(Callback);
	Request->SetMethod("POST");
	Request->SetContentType(ContentType);
	Request->SetContent(Content);
	Request->Send(Url);
}

// When we send POST request, Content-Type is required by Unreal Engine
void USfHttpComponent::SendHttpPostRequestWithHeaders(FString Url, FString ContentType, TMap<FString, FString> Headers, FString Content, const FOnRequestComplete& Callback)
{
	USfHttpRequest* Request = NewObject<USfHttpRequest>();
	Request->SetCallback(Callback);
	Request->SetMethod("POST");
	Request->SetContentType(ContentType);
	Request->SetHeaders(Headers);
	Request->SetContent(Content);
	Request->Send(Url);
}
