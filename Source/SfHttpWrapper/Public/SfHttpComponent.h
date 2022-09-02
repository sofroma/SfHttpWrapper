// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SfHttpRequest.h"
#include "SfHttpComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SFHTTPWRAPPER_API USfHttpComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USfHttpComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable, Category = "Sf Http")
	void SendHttpRequest(FString Url, const FOnRequestComplete& Callback);

	UFUNCTION(BlueprintCallable, Category = "Sf Http")
	void SendHttpRequestWithHeaders(FString Url, TMap<FString, FString> Headers, const FOnRequestComplete& Callback);

	UFUNCTION(BlueprintCallable, Category = "Sf Http")
	void SendHttpPostRequest(FString Url, FString ContentType, FString Content, const FOnRequestComplete& Callback);

	UFUNCTION(BlueprintCallable, Category = "Sf Http")
	void SendHttpPostRequestWithHeaders(FString Url, FString ContentType, TMap<FString, FString> Headers, FString Content, const FOnRequestComplete& Callback);

};
