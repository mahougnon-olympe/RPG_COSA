
/*
** EPITECH PROJECT, 2025
** menu
** File description:
** description
*/

#include "../include/my_rpg.h"

menu_t *init(void)
{
    menu_t *mn;

    mn->pic = sfTexture_createFromFile("ressources/accueil.png", NULL);
    mn->picture = sfSprite_create();
    mn->sc = (sfVector2f){2.16, 1.83};

    mn->btn = sfTexture_createFromFile("ressources/play.png", NULL);
    mn->button = sfSprite_create();
    mn->bt_sc = (sfVector2f){0.90, 0.90};
    mn->bt_pos = (sfVector2f){800, 500};

    mn->mr = sfTexture_createFromFile("ressources/more.png", NULL);
    mn->more = sfSprite_create();
    mn->mr_sc = (sfVector2f){0.90, 0.90};
    mn->mr_pos = (sfVector2f){800, 100};

    mn->pm = sfTexture_createFromFile("ressources/pmore.png", NULL);
    mn->pmore = sfSprite_create();
    mn->pm_sc = (sfVector2f){2.16, 2.14};

    mn->sr = sfTexture_createFromFile("ressources/score.png", NULL);
    mn->score = sfSprite_create();
    mn->sr_sc = (sfVector2f){0.90, 0.90};
    mn->sr_pos = (sfVector2f){800, 250};

    sfSprite_setTexture(mn->picture, mn->pic, sfTrue);
    sfSprite_setScale(mn->picture, mn->sc);

    sfSprite_setTexture(mn->button, mn->btn, sfTrue);
    sfSprite_setScale(mn->button, mn->bt_sc);
    sfSprite_setPosition(mn->button, mn->bt_pos);

    sfSprite_setTexture(mn->more, mn->mr, sfTrue);
    sfSprite_setScale(mn->more, mn->mr_sc);
    sfSprite_setPosition(mn->more, mn->mr_pos);

    sfSprite_setTexture(mn->pmore, mn->pm, sfTrue);
    sfSprite_setScale(mn->pmore, mn->pm_sc);

    sfSprite_setTexture(mn->score, mn->sr, sfTrue);
    sfSprite_setScale(mn->score, mn->sr_sc);
    sfSprite_setPosition(mn->score, mn->sr_pos);

    return mn;
}

void page_more(menu_t *mn, sfRenderWindow* window, sfEvent event)
{
    while (sfRenderWindow_isOpen(window)) {
        handle_event(window, event);
        sfRenderWindow_clear(window, sfColor_fromRGB(50, 50, 50));
        sfRenderWindow_drawSprite(window, mn->pmore, NULL);
        sfRenderWindow_display(window);
    }
}

void for_return(sfSprite *sprite)
{
    sfSprite_destroy(sprite);
    the_window();

}

void page_score(menu_t *mn, sfRenderWindow* window, sfEvent event)
{
    sfMouseButton button;

    while (sfRenderWindow_isOpen(window)) {
        handle_event(window, event);
        sfRenderWindow_clear(window, sfColor_fromRGB(50, 50, 50));
        sfRenderWindow_drawSprite(window, mn->pmore, NULL);
        //sfRenderWindow_display(window);
	if (sfMouse_isButtonPressed(button) == sfTrue)
	    printf("yooo");//for_return(mn->pmore);
	sfRenderWindow_display(window);
    }
}

void next(menu_t *mn, sfRenderWindow* window, sfEvent event, struct epi *pi)
{
    const sfWindow*wdw = (const sfWindow*)window;
    sfMouseButton button;

    mn->ms_pos = sfMouse_getPosition(wdw);
//    if (sfMouse_isButtonPressed(button) == sfTrue)
    //  printf("x = %d y = %d\n", mn->ms_pos.x, mn->ms_pos.y);
    if(mn->ms_pos.x >= 810 && mn->ms_pos.x <= 1027) {
	if(mn->ms_pos.y >= 50 && mn->ms_pos.y <= 570) {
	    if (sfMouse_isButtonPressed(button) == sfTrue)
		printf("yeah");
	}
    }

    if(mn->ms_pos.x >= 803 && mn->ms_pos.x <= 1033) {
	if(mn->ms_pos.y >= 101 && mn->ms_pos.y <= 176) {
	    if (sfMouse_isButtonPressed(button) == sfTrue)
		page_more(mn, window,event);
	}
    }

    if(mn->ms_pos.x >= 815 && mn->ms_pos.x <= 1017) {
	if(mn->ms_pos.y >= 261 && mn->ms_pos.y <= 323) {
            if (sfMouse_isButtonPressed(button) == sfTrue) {
                page_score(mn, window,event);
		if (sfMouse_isButtonPressed(button) == sfTrue)
		    printf("yoo");
	    }
        }
    }
}
