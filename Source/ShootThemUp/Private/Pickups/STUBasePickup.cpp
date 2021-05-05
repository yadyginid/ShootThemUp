// Shoot Them Up Game. All right reserved.

#include "Pickups/STUBasePickup.h"
#include "Components/SphereComponent.h"

DEFINE_LOG_CATEGORY_STATIC(LogBasePickup, All, All);

ASTUBasePickup::ASTUBasePickup()
{
    PrimaryActorTick.bCanEverTick = true;

    CollisionComponent = CreateDefaultSubobject<USphereComponent>("SphereComponent");
    CollisionComponent->InitSphereRadius(50.0f);
    CollisionComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
    CollisionComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
    SetRootComponent(CollisionComponent);
}

void ASTUBasePickup::BeginPlay()
{
    Super::BeginPlay();

    check(CollisionComponent);

    GenerataRotationYaw();
}

void ASTUBasePickup::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    AddActorLocalRotation(FRotator(0.0f, RotationYaw, 0.0f));
}

void ASTUBasePickup::NotifyActorBeginOverlap(AActor* OtherActor)
{
    Super::NotifyActorBeginOverlap(OtherActor);

    const auto Pawn = Cast<APawn>(OtherActor);
    if (GivePickUpTo(Pawn))
    {
        PickupWasTaken();
    }
}

void ASTUBasePickup::PickupWasTaken()
{
    CollisionComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);

    if (GetRootComponent())
    {
        GetRootComponent()->SetVisibility(false, true);
    }

    FTimerHandle RespawnTimeHandle;
    GetWorldTimerManager().SetTimer(RespawnTimeHandle, this, &ASTUBasePickup::Respawn, RespawnTime);
}

void ASTUBasePickup::Respawn()
{
    CollisionComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);

    if (GetRootComponent())
    {
        GetRootComponent()->SetVisibility(true, true);
    }

    GenerataRotationYaw();
}

// can take pickup
bool ASTUBasePickup::GivePickUpTo(APawn* PlayerPawn)
{
    return false;
}

void ASTUBasePickup::GenerataRotationYaw()
{
    const auto Direction = FMath::RandBool() ? 1.0f : -1.0f;
    RotationYaw = FMath::FRandRange(1.0f, 2.0f) * Direction;
}