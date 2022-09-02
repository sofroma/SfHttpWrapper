// Fill out your copyright notice in the Description page of Project Settings.


#include "SfHttpRequest.h"

void USfHttpRequest::Send(FString Url)
{
	FHttpModule* Module = &FHttpModule::Get();
	TSharedRef<IHttpRequest, ESPMode::ThreadSafe> Request = Module->CreateRequest();
	Request->OnProcessRequestComplete().BindUObject(this, &USfHttpRequest::OnRequestComplete);
	Request->SetVerb(Method);
	Request->SetURL(Url);
	if(!Headers.IsEmpty())
	{
		for(auto& Elem : Headers)
		{
			Request->SetHeader(Elem.Key, Elem.Value);
		}
	}
	if(Request->GetVerb().Equals("POST", ESearchCase::CaseSensitive))
	{
		if(!ContentType.IsEmpty())
		{
			Request->SetHeader("Content-Type", ContentType);
		} else
		{
			Request->SetHeader("Content-Type", "text/plain");
		}

		if(!RequestBody.IsEmpty())
		{
			Request->SetContentAsString(RequestBody);
		}
	}
	
	Request->ProcessRequest();
}

void USfHttpRequest::SetCallback(FOnRequestComplete NewCallback)
{
	Callback = NewCallback;
}

void USfHttpRequest::OnRequestComplete(FHttpRequestPtr Request, FHttpResponsePtr Response, bool Success)
{
	int32 Code = 0;
	FString Content = "";
	if(Success)
	{
		Code = Response->GetResponseCode();
		Content = Response->GetContentAsString();
	}
	Callback.ExecuteIfBound(Success, Code, Content);
}

void USfHttpRequest::SetMethod(FString NewMethod)
{
	Method = NewMethod;
}

void USfHttpRequest::SetContent(FString Content)
{
	RequestBody = Content;
}

void USfHttpRequest::SetHeaders(TMap<FString, FString> NewHeaders)
{
	Headers = NewHeaders;
}

void USfHttpRequest::SetContentType(FString NewContentType)
{
	ContentType = NewContentType;
}
