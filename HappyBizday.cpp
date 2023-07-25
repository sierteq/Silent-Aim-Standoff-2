UIWindow *esp_window;
#define ScreenWidth  esp_window.frame.size.width
#define ScreenHeight esp_window.frame.size.height

void *(*Component$$get_transform)(void *) = (void *(*)(void *)) getRealOffset(0x346CF8C);
Vector3 (*Transform$$get_position)(void *) = (Vector3 (*)(void *)) getRealOffset(0x3476B24);
bool (*PlayerController$$get_IsLocal)(void *) = (bool (*)(void *)) getRealOffset(0x1AFF570);
int (*PlayerController$$GetTeam)(void *) = (int (*)(void *)) getRealOffset(0x1B02D48);
void *(*Camera$$get_main)() = (void *(*)()) getRealOffset(0x344C6C4);
Vector3 (*Camera$$WorldToScreenPoint)(void *, Vector3, int) = (Vector3 (*)(void *, Vector3, int)) getRealOffset(0x344BF80);

struct me_t{
void *object;
Vector3 position;
};
me_t *me;

struct enemy_t{
void *object;
void *biped;
void *head;
Vector3 headposition;
Vector3 headonscreen;
};
enemy_t *enemy;

Vector3 GetPlayerLocation(void *player){
return Vector3(Transform$$get_position(Component$$get_transform(player)));
}

bool Get_IsLocal(void *player)
{
return bool(PlayerController$$get_IsLocal(player));
}

int GetPlayerTeam(void *player)
{
return int(PlayerController$$GetTeam(player));
}

Vector3 WorldOnScreen(Vector3 player){
return Vector3(Camera$$WorldToScreenPoint(Camera$$get_main(), player, 2));
}


// Спасибо за покупку! :-))

float fov = 0;
void (*old_playerupdate)(void *player);
void new_playerupdate(void *player){
if (Get_IsLocal(player) && Get_IsLocal(player) != false){
if( Get_IsLocal(player) == true){
 me->object = player;
 me->position = GetPlayerLocation(me->object);
}}


if (NULL != me->object && me->object != NULL){
if (me->object){
if (GetPlayerTeam(me->object) != GetPlayerTeam(player) && GetPlayerTeam(player) != GetPlayerTeam(enemy->object)){
enemy->object = player;
enemy->biped = *(void **)((uint64_t)enemy->object + 0x30);
enemy->head = *(void **)((uint64_t)enemy->biped + 0x18);
enemy->headposition = GetPlayerLocation(enemy->head);
       enemy->headonscreen = WorldOnScreen(enemy->headposition);
}

				    /*
				    if (me->health > 0 && enemy->health > 0){
				    	fov = [[switches getValueFromSwitch:@"FOV:"] floatValue];
				 }   */
}}  else{
old_playerupdate(player);
return;
}
 old_playerupdate(player);
}

void (*old_silentaim)(void *_this, Vector3 startPosition, Vector3 direction, void *parameters);
void new_silentaim(void *_this, Vector3 startPosition, Vector3 direction, void *parameters)
{
if ([switches isSwitchOn:@"Silent Aim"] /* && enemy->visible */){
if ([switches isSwitchOn:@"FOV Check"] && fov > 0 && !(![switches isSwitchOn:@"FOV Check"])){
Vector2 Position = {static_cast<float>(enemy->headonscreen.x - ScreenWidth / 2), static_cast<float>(enemy->headonscreen.y - ScreenHeight / 2)};
Vector2 mPos = {static_cast<float>(fov + fov / 2 + ScreenWidth / 2), static_cast<float>(fov + fov / 2 + ScreenHeight / 2)};
if (Vector2::Magnitude(Position) < mPos.x && Vector2::Magnitude(Position) < mPos.y){ // Thanks for your purchase
direction.x = enemy->headposition.x - startPosition.x;
direction.y = enemy->headposition.y - startPosition.y;
direction.z = enemy->headposition.z - startPosition.z;
}}else{
direction.x = enemy->headposition.x - startPosition.x;
direction.y = enemy->headposition.y - startPosition.y;
direction.z = enemy->headposition.z - startPosition.z;
}} else{
old_silentaim(_this, startPosition, direction, parameters);
return;
}
 old_silentaim(_this, startPosition, direction, parameters);
}


void setup(){
me=new me_t();
enemy=new enemy_t();
HOOK(0x1B01BE0, new_playerupdate, old_playerupdate);
HOOK(0x1CFBD28, new_silentaim, old_silentaim);
[switches addSwitch:@"Silent Aim" description: nil];
[switches addSwitch:@"FOV Check" description: nil];
}


/**
 * Спасибо за приобретение
 * Don't share pls
 * НЕ РАСПРОСТРОНЯТЬ
 * DON'T SHARE F*CKN B*TCH
 */


void setupMenu(){ // Спасибо, что приобрели продукт
   menu = [[Menu alloc] ...];
 esp_window = [UIApplication sharedApplication].keyWindow;
}
