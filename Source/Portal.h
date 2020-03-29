#ifndef Portal_H
#define Portal_H
namespace game_framework
{
class Portal
{
    public:
        Portal(int, int, int);
        ~Portal();
    private:
        int color;
        CAnimation animation;
        int x, y;
        
};
}
#endif