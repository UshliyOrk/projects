import pygame

pygame.init()
win = pygame.display.set_mode((500, 500))
pygame.display.set_caption("first pygame platformer")
clock = pygame.time.Clock()

x = 50
y = 424
width = 60
height = 71
speed = 5

jumpCount = 10
isjump = False

left = False
right = False
anim = 0
iml = pygame.image.load
walkLeft = [iml('l1.png'), iml('l2.png'), iml('l3.png'), iml('l4.png'), iml('l5.png'), iml('l6.png')]
walkRight = [iml('r1.png'), iml('r2.png'), iml('r3.png'), iml('r4.png'), iml('r5.png'), iml('r6.png')]
stand = iml('idle.png')
bg = iml('bg.jpg')

run = True

def frame():
    global anim
    win.blit(bg, (0, 0))
    if anim + 1 >= 30:
        anim = 0

    if left:
        win.blit(walkLeft[anim // 5], (x, y))
        anim += 1
    elif right:
        win.blit(walkRight[anim // 5], (x, y))
        anim += 1
    else:
        win.blit(stand, (x, y))
    pygame.display.update()

while run:
    clock.tick(30)

    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            run = False
    keys = pygame.key.get_pressed()
    if keys[pygame.K_d] and x < 500 - width - 5:
        x += speed
        right = True
        left = False
    elif keys[pygame.K_a] and x > 5:
        x -= speed
        right = False
        left = True
    else:
        left = False
        right = False
        anim = 0
    if not isjump:
        if keys[pygame.K_SPACE]:
            isjump = True
    else:
        if jumpCount >= -10:
            if jumpCount < 0:
                y += (jumpCount**2)/2
            else:
                y -= (jumpCount**2)/2
            jumpCount -= 1
        else:
            isjump = False
            jumpCount = 10

    frame()

pygame.quit()