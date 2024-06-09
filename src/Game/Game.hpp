#ifndef GAME
#define GAME

#include "Globals.hpp"

#include <algorithm>
#include <cmath>
#include <string>

struct Ball
{
    cc::Texture texture;

    int posX = 0;
    int posY = 0;

    float baseSpeed = 500.0f;

    float velX = baseSpeed;
    float velY = baseSpeed;

    float centerX = 0.0f;
    float centerY = 0.0f;

    bool moveVertically = false;
};

struct Player
{
    cc::Texture texture;

    int posX = 0;
    int posY = 0;

    int score = 0;

    float velocity = 0.0f;
};

struct Enemy
{
    cc::Texture texture;

    int posX = 0;
    int posY = 0;

    int score = 0;

    float velocity = 0.0f;
};

class GameScene : public cc::Scene
{
    using cc::Scene::Scene;

    Gamevars *gv = Gamevars::GetInstance();

    cc::Text playerScoreText;
    int pTextPos = SCREEN_WIDTH / 4;

    cc::Text enemyScoreText;
    int eTextPos = SCREEN_WIDTH / 4 + SCREEN_WIDTH / 2;

    cc::Text winText;
    int wTextPosX = 0;
    int wTextPosY = 0;

    cc::Text restartText;
    int rTextPosX = 0;
    int rTextPosY = SCREEN_HEIGHT / 4 + SCREEN_HEIGHT / 2;

    Ball ball;
    Player player;
    Enemy enemy;

    float minForceFactor = 0.5f;
    float maxForceFactor = 1.0f;
    float speedMultiplier = 3.5f;

    bool playerServing = false;
    bool gameOver = false;

    int maxScore = 11;
    int consecutiveServes = 1;

    cc::Window *window = cc::Window::GetInstance();

    void HandleBallCollisions(Ball &ball, Player &player, Enemy &enemy)
    {
        cc::Texture paddle;

        ball.centerX = ball.texture.textureQuad.x + ball.texture.textureQuad.w;
        ball.centerY = ball.texture.textureQuad.y + ball.texture.textureQuad.h;

        bool collisionPaddle = (ball.centerX < (SCREEN_WIDTH / 2.0f));

        paddle.textureQuad = (collisionPaddle ? player.texture.textureQuad : enemy.texture.textureQuad);

        if (ball.centerX >= paddle.textureQuad.x &&
            ball.centerX <= paddle.textureQuad.x + paddle.textureQuad.w &&
            ball.centerY >= paddle.textureQuad.y &&
            ball.centerY <= paddle.textureQuad.y + paddle.textureQuad.h)
        {
            gv->ballHitSFX.Play();

            ball.moveVertically = true;

            float relativeY = ball.centerY - (paddle.textureQuad.y + paddle.textureQuad.h / 2.0f);

            float forceFactor = std::lerp(minForceFactor, maxForceFactor,
                                          (relativeY + paddle.textureQuad.h / 2.0f) / paddle.textureQuad.h);
            float speedFactor = std::abs((collisionPaddle ? player.velocity : enemy.velocity) * gv->timeStep);

            forceFactor *= speedFactor;

            ball.velX *= -1.0f;

            if (collisionPaddle)
            {
                if (ball.velY == 0.0f)
                { ball.velY = -ball.baseSpeed; }
                else if (ball.velY != 0.0f && std::abs(player.velocity) > 0.01f)
                { ball.velY = std::clamp(player.velocity * gv->timeStep, -ball.baseSpeed, ball.baseSpeed) * forceFactor * speedMultiplier; }
            }
            else
            {
                if (ball.velY == 0.0f)
                { ball.velY = -ball.baseSpeed; }
                else if (ball.velY != 0.0f && std::abs(enemy.velocity) > 0.01f)
                { ball.velY = std::clamp(enemy.velocity * gv->timeStep, -ball.baseSpeed, ball.baseSpeed) * forceFactor * speedMultiplier; }
            }
        }

        if (ball.texture.textureQuad.y + ball.texture.textureQuad.h <= 0.0f)
        { ball.velY = -ball.velY; }
        else if (ball.texture.textureQuad.y + ball.texture.textureQuad.h >= SCREEN_HEIGHT)
        { ball.velY = -ball.velY; }

        if (ball.texture.textureQuad.x + ball.texture.textureQuad.w <= 0.0f)
        {
            enemy.score++;

            enemyScoreText.Update(std::to_string(enemy.score).c_str(), gv->fontBig.font, { 255, 255, 255 }, eTextPos, 0);

            ball.texture.SetPosition(ball.posX, ball.posY);
            ball.moveVertically = false;

            HandleServing(ball, player, enemy);
        }
        else if (ball.texture.textureQuad.x + ball.texture.textureQuad.w >= SCREEN_WIDTH)
        {
            player.score++;

            playerScoreText.Update(std::to_string(player.score).c_str(), gv->fontBig.font, { 255, 255, 255 }, pTextPos, 0);

            ball.texture.SetPosition(ball.posX, ball.posY);
            ball.moveVertically = false;

            HandleServing(ball, player, enemy);
        }

        ball.texture.textureQuad.x += ball.velX * gv->timeStep;
        ball.texture.textureQuad.y += (ball.moveVertically ? ball.velY : 0.0f) * gv->timeStep;
    }

    void HandleServing(Ball &ball, Player &player, Enemy &enemy)
    {
        if (consecutiveServes == 2 && player.score + enemy.score < 20)
        {
            consecutiveServes = 1;
            playerServing = !playerServing;
        }
        else if (consecutiveServes >= 0 && player.score + enemy.score >= 20)
        {
            consecutiveServes = 0;
            playerServing = !playerServing;
        }
        else
        { consecutiveServes++; }

        ball.velX = playerServing ? -ball.baseSpeed : ball.baseSpeed;
    }

    void HandleScore(Ball &ball, Player &player, Enemy &enemy)
    {
        if (std::abs(player.score - enemy.score) >= 2)
        {
            if (player.score >= maxScore && player.score > enemy.score)
            {
                gameOver = true;

                winText.Update("PLAYER 1 WINS!", gv->fontBig.font, { 255, 255, 255 }, wTextPosX, wTextPosY);
                wTextPosX = SCREEN_WIDTH / 2 - winText.TEXT_CENTER_W;
                wTextPosY = SCREEN_HEIGHT / 2 - winText.TEXT_CENTER_H;
                winText.SetX(wTextPosX);
                winText.SetY(wTextPosY);

                restartText.Update("PRESS R TO RESTART", gv->fontSmall.font, { 255, 255, 255 }, rTextPosX, rTextPosY);
                rTextPosX = SCREEN_WIDTH / 2 - restartText.TEXT_CENTER_W;
                restartText.SetX(rTextPosX);
                restartText.SetY(rTextPosY);

                ball.velX = 0.0f;
                gv->speed = 0.0f;

                ball.texture.SetAlpha(0);
                player.texture.SetAlpha(0);
                enemy.texture.SetAlpha(0);

                player.texture.SetPosition(player.posX, player.posY);
                enemy.texture.SetPosition(enemy.posX, enemy.posY);

                playerScoreText.Update("", gv->fontBig.font, { 0, 0, 0 }, -100, -100);
                enemyScoreText.Update("", gv->fontBig.font, { 0, 0, 0 }, -100, -100);
            }
            else if (enemy.score >= maxScore && enemy.score > player.score)
            {
                gameOver = true;

                winText.Update("PLAYER 2 WINS!", gv->fontBig.font, { 255, 255, 255 }, wTextPosX, wTextPosY);
                wTextPosX = SCREEN_WIDTH / 2 - winText.TEXT_CENTER_W;
                wTextPosY = SCREEN_HEIGHT / 2 - winText.TEXT_CENTER_H;
                winText.SetX(wTextPosX);
                winText.SetY(wTextPosY);

                restartText.Update("PRESS R TO RESTART", gv->fontSmall.font, { 255, 255, 255 }, rTextPosX, rTextPosY);
                rTextPosX = SCREEN_WIDTH / 2 - restartText.TEXT_CENTER_W;
                restartText.SetX(rTextPosX);
                restartText.SetY(rTextPosY);

                ball.velX = 0.0f;
                gv->speed = 0.0f;

                ball.texture.SetAlpha(0);
                player.texture.SetAlpha(0);
                enemy.texture.SetAlpha(0);

                player.texture.SetPosition(player.posX, player.posY);
                enemy.texture.SetPosition(enemy.posX, enemy.posY);

                playerScoreText.Update("", gv->fontBig.font, { 0, 0, 0 }, -100, -100);
                enemyScoreText.Update("", gv->fontBig.font, { 0, 0, 0 }, -100, -100);
            }
        }
    }

    void OnStart() override
    {
        ball.texture.Create(window->GetRenderer(), "./resources/textures/ball.png");
        ball.posX = SCREEN_WIDTH / 2 - ball.texture.textureCenterX;
        ball.posY = SCREEN_HEIGHT / 2 - ball.texture.textureCenterY;
        ball.texture.SetPosition(ball.posX, ball.posY);

        player.texture.Create(window->GetRenderer(), "./resources/textures/paddle.png");
        player.posX = 0;
        player.posY = SCREEN_HEIGHT / 2 - player.texture.textureCenterY;
        player.texture.SetPosition(player.posX, player.posY);

        enemy.texture.Create(window->GetRenderer(), "./resources/textures/paddle.png");
        enemy.posX = SCREEN_WIDTH - enemy.texture.textureQuad.w;
        enemy.posY = SCREEN_HEIGHT / 2 - enemy.texture.textureCenterY;
        enemy.texture.SetPosition(enemy.posX, enemy.posY);

        enemy.score = 0;

        playerScoreText.Create(window->GetRenderer(), std::to_string(player.score).c_str(), gv->fontBig.font, { 255, 255, 255 }, pTextPos, 0, playerScoreText.CENTER);
        enemyScoreText.Create(window->GetRenderer(), std::to_string(enemy.score).c_str(), gv->fontBig.font, { 255, 255, 255 }, eTextPos, 0, enemyScoreText.CENTER);

        winText.Create(window->GetRenderer(), "WINS!", gv->fontBig.font);

        restartText.Create(window->GetRenderer(), "PRESS R TO RESTART", gv->fontSmall.font);

        handleKeyStatesAlone = true;
    }

    void OnExit() override
    {
        ball.texture.Destroy();
        player.texture.Destroy();
        enemy.texture.Destroy();

        playerScoreText.Destroy();
        enemyScoreText.Destroy();

        winText.Destroy();

        restartText.Destroy();
    }

    void OnHandleInput() override
    {
        while (cc::Event::PollEvent(&gv->e))
        {
            if (gv->e.type == cc::Event::CC_QUIT)
            { Quit(); }
            if (gv->e.type == cc::Event::CC_KEYDOWN)
            {
                switch (gv->e.key.keysym.sym)
                {
                    case cc::Keyboard::CCK_ESCAPE:
                        SwitchScene("mainMenu");
                        break;

                    case cc::Keyboard::CCK_R:
                        if (gameOver)
                        {
                            player.score = 0;
                            enemy.score = 0;

                            ball.velX = ball.baseSpeed;
                            gv->speed = 800.0f;

                            playerScoreText.Update(std::to_string(player.score).c_str(), gv->fontBig.font, { 255, 255, 255 }, pTextPos, 0);
                            enemyScoreText.Update(std::to_string(enemy.score).c_str(), gv->fontBig.font, { 255, 255, 255 }, eTextPos, 0);

                            ball.texture.SetAlpha(255);
                            player.texture.SetAlpha(255);
                            enemy.texture.SetAlpha(255);

                            gameOver = false;
                        }
                        break;

                    default:
                        break;
                }
            }
        }
    }

    void OnHandleKeyStates() override
    {
        if (keyStates[cc::Scancode::CCS_W] && !keyStates[cc::Scancode::CCS_S])
        {
            if (player.texture.textureQuad.y <= 0)
            { player.texture.textureQuad.y = 0; }
            else
            { player.velocity = -gv->speed; }
        }
        if (keyStates[cc::Scancode::CCS_S] && !keyStates[cc::Scancode::CCS_W])
        {
            if (player.texture.textureQuad.y >= SCREEN_HEIGHT - player.texture.textureQuad.h)
            { player.texture.textureQuad.y = SCREEN_HEIGHT - player.texture.textureQuad.h; }
            else
            { player.velocity = gv->speed; }
        }
        if (keyStates[cc::Scancode::CCS_UP] && !keyStates[cc::Scancode::CCS_DOWN])
        {
            if (enemy.texture.textureQuad.y <= 0)
            { enemy.texture.textureQuad.y = 0; }
            else
            { enemy.velocity = -gv->speed; }
        }
        if (keyStates[cc::Scancode::CCS_DOWN] && !keyStates[cc::Scancode::CCS_UP])
        {
            if (enemy.texture.textureQuad.y >= SCREEN_HEIGHT - enemy.texture.textureQuad.h)
            { enemy.texture.textureQuad.y = SCREEN_HEIGHT - enemy.texture.textureQuad.h; }
            else
            { enemy.velocity = gv->speed; }
        }
    }

    void OnUpdate() override
    {
        gv->gTime.UpdateClock();

        gv->accumulatedTime += gv->gTime.GetDeltaTime();

        while (gv->accumulatedTime >= gv->timeStep)
        {
            player.velocity = 0.0f;
            enemy.velocity = 0.0f;

            OnHandleKeyStates();

            player.texture.textureQuad.y += player.velocity * gv->timeStep;
            enemy.texture.textureQuad.y += enemy.velocity * gv->timeStep;

            HandleBallCollisions(ball, player, enemy);

            HandleScore(ball, player, enemy);

            gv->ballHitSFX.Expire();

            gv->accumulatedTime -= gv->timeStep;
        }

        gv->DebugUpdate();
    }

    void OnRender() override
    {
        ball.texture.Render();

        player.texture.Render();
        enemy.texture.Render();

        playerScoreText.Render();
        enemyScoreText.Render();

        if (gameOver)
        {
            winText.Render();
            restartText.Render();
        }

        gv->DebugRender();
    }
};

#endif // GAME
