//SPRITE.H
//********

//olika sprite-typer
#define SP_BOAT   0 //båt
#define SP_LIGHT  1 //ljuseffekt
#define SP_BULLET 2 //skott (används inte)
#define SP_EDIT   3 //muspekare i editorn
#define SP_BONUS  4 //används inte
#define SP_OTHER  5 //samma här

//används när man laddar banor
struct boatcoord {
 fixed x,y;
 fixed a;
};

//en sprite (en basklass som boat, light m m ärver från)
class sprite {
 public:
  sprite(fixed newx, fixed newy);
  virtual ~sprite();
  int getX() {return x;}
  int getY() {return y;}
  virtual void draw(BITMAP *bmp,fixed sx,fixed sy)=0;
  virtual void move()=0;
  void bringtofront(); //funkar ej
  void sendtoback();   //funkar ej
  void moveto(fixed _x,fixed _y) {x=_x; y=_y;}
  static void moveall();
  static void killall();
  static sprite *findat(fixed x, fixed y, int type);
  int collided(sprite *sp);
  int hit(fixed _x,fixed _y) {
   if (fixsqrt(fixmul(x-_x,x-_x)+fixmul(y-_y,y-_y)) < itofix(1))
    return 1;
   else
    return 0;
  }
  virtual void writetofile(PACKFILE *f)=0;
  virtual void readfromfile(PACKFILE *f)=0;
  static int numsprites() {return spritecount;}
  sprite *pnext;
  static sprite *pfirst;
  int type;
  fixed x,y;
  int size;
  int valid;
 protected:
  static int spritecount;
  int tobedeleted;
};


