// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/CC_PlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "GameFramework/Character.h"

void ACC_PlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	//获取系统
	UEnhancedInputLocalPlayerSubsystem* InputSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());

	if (!IsValid(InputSubsystem))return;
	//把映射加到系统
	for (auto context:InputMappingContexts)
	{
		InputSubsystem->AddMappingContext(context,0);
	}

	UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent);
	if (!IsValid(EnhancedInputComponent))return;
	
	EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &ThisClass::Jump);
	EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ThisClass::StopJump);
	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ThisClass::Move);
	EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &ThisClass::Look);
	
	EnhancedInputComponent->BindAction(PrimaryAction, ETriggerEvent::Started, this, &ThisClass::Primary);
}

void ACC_PlayerController::Jump()
{
	if (!IsValid(GetCharacter()))return;
	GetCharacter()->Jump();
}

void ACC_PlayerController::StopJump()
{
	if (!IsValid(GetCharacter()))return;
	GetCharacter()->StopJumping();
}

void ACC_PlayerController::Look(const FInputActionValue& Value)
{
	if (!IsValid(GetCharacter()))return;
	const FVector2D LookAxisVector = Value.Get<FVector2D>();
	AddYawInput(LookAxisVector.X);
	AddPitchInput(LookAxisVector.Y);
}

void ACC_PlayerController::Move(const FInputActionValue& Value)
{
	if (!IsValid(GetCharacter()))return;
	const FVector2D MoveVector = Value.Get<FVector2D>();

	const FRotator YawRotation(0.f,GetControlRotation().Yaw,0.f);
	const FVector Forward = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector Right = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	GetCharacter()->AddMovementInput(Forward,MoveVector.Y);
	GetCharacter()->AddMovementInput(Right,MoveVector.X);
}

void ACC_PlayerController::Primary()
{
	
}
