// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpectralVisualizer.generated.h"

UCLASS()
class AUDIOVIZ_API ASpectralVisualizer : public AActor {
  GENERATED_BODY()

public:
  // Sets default values for this actor's properties
  ASpectralVisualizer();

protected:
  // Called when the game starts or when spawned
  void BeginPlay() override;
  void PostEditChangeProperty(FPropertyChangedEvent &PropertyChangedEvent) override;

  void Refresh();

  UPROPERTY(EditAnywhere, Category = "Audio")
  class UTimeSynthComponent *TimeSynthComponent;

  UPROPERTY(EditAnywhere, Category = "Audio")
  class UTimeSynthClip *TimeSynthClip{};

  UPROPERTY(EditAnywhere, Category = "Audio")
  TArray<UStaticMeshComponent*> SpectrumBars;

  UPROPERTY(EditAnywhere, Category = "Audio")
  UStaticMesh *SpectrumBarMesh{};

  UPROPERTY(EditAnywhere, Category = "Audio")
  float SpectrumBarSpacing;

  UPROPERTY(EditAnywhere, Category = "Audio")
  float InterpolationSpeed;

public:
  // Called every frame
  void Tick(float DeltaTime) override;

};
