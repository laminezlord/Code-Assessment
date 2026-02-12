
import pygame
import sys

# Initialize Pygame
pygame.init()

# Constants
WIDTH, HEIGHT = 600, 700
LINE_WIDTH = 15
BOARD_ROWS = 3
BOARD_COLS = 3
SQUARE_SIZE = WIDTH // BOARD_COLS
CIRCLE_RADIUS = SQUARE_SIZE//3
CIRCLE_WIDTH = 15
CROSS_WIDTH = 25
SPACE = SQUARE_SIZE//4

# Colors
BG_COLOR = (28, 170, 156)
LINE_COLOR = (23, 145, 135)
CIRCLE_COLOR = (239, 231, 200)
CROSS_COLOR = (66, 66, 66)
TEXT_COLOR = (255, 255, 255)
BUTTON_COLOR = (50, 50, 50)

# Screen
screen = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("X and O Game")
screen.fill(BG_COLOR)

# Fonts
font = pygame.font.SysFont(None, 40)

# Board
board = [[0 for _ in range(BOARD_COLS)] for _ in range(BOARD_ROWS)]
score_player = 0
score_ai = 0

# Draw lines
def draw_lines():
    # Horizontal
    pygame.draw.line(screen, LINE_COLOR, (0, SQUARE_SIZE), (WIDTH, SQUARE_SIZE), LINE_WIDTH)
    pygame.draw.line(screen, LINE_COLOR, (0, 2*SQUARE_SIZE), (WIDTH, 2*SQUARE_SIZE), LINE_WIDTH)
    # Vertical
    pygame.draw.line(screen, LINE_COLOR, (SQUARE_SIZE,0), (SQUARE_SIZE, HEIGHT-100), LINE_WIDTH)
    pygame.draw.line(screen, LINE_COLOR, (2*SQUARE_SIZE,0), (2*SQUARE_SIZE, HEIGHT-100), LINE_WIDTH)

# Draw figures
def draw_figures():
    for row in range(BOARD_ROWS):
        for col in range(BOARD_COLS):
            if board[row][col] == 1:
                pygame.draw.circle(screen, CIRCLE_COLOR, (int(col*SQUARE_SIZE+SQUARE_SIZE/2), int(row*SQUARE_SIZE+SQUARE_SIZE/2)), CIRCLE_RADIUS, CIRCLE_WIDTH)
            elif board[row][col] == 2:
                pygame.draw.line(screen, CROSS_COLOR, (col*SQUARE_SIZE+SPACE, row*SQUARE_SIZE+SQUARE_SIZE-SPACE), 
                                 (col*SQUARE_SIZE+SQUARE_SIZE-SPACE, row*SQUARE_SIZE+SPACE), CROSS_WIDTH)
                pygame.draw.line(screen, CROSS_COLOR, (col*SQUARE_SIZE+SPACE, row*SQUARE_SIZE+SPACE), 
                                 (col*SQUARE_SIZE+SQUARE_SIZE-SPACE, row*SQUARE_SIZE+SQUARE_SIZE-SPACE), CROSS_WIDTH)

# Check win
def check_win(player):
    for col in range(BOARD_COLS):
        if board[0][col]==board[1][col]==board[2][col]==player:
            return True
    for row in range(BOARD_ROWS):
        if board[row][0]==board[row][1]==board[row][2]==player:
            return True
    if board[0][0]==board[1][1]==board[2][2]==player:
        return True
    if board[0][2]==board[1][1]==board[2][0]==player:
        return True
    return False

def board_full():
    for row in range(BOARD_ROWS):
        for col in range(BOARD_COLS):
            if board[row][col]==0:
                return False
    return True

# AI using minimax
def minimax(board_state, depth, is_ai):
    if check_win(2):
        return 10 - depth
    if check_win(1):
        return depth - 10
    if board_full():
        return 0
    if is_ai:
        best = -1000
        for i in range(BOARD_ROWS):
            for j in range(BOARD_COLS):
                if board_state[i][j]==0:
                    board_state[i][j]=2
                    score = minimax(board_state, depth+1, False)
                    board_state[i][j]=0
                    if score>best: best=score
        return best
    else:
        best = 1000
        for i in range(BOARD_ROWS):
            for j in range(BOARD_COLS):
                if board_state[i][j]==0:
                    board_state[i][j]=1
                    score = minimax(board_state, depth+1, True)
                    board_state[i][j]=0
                    if score<best: best=score
        return best

def ai_move():
    best_score = -1000
    move = None
    for i in range(BOARD_ROWS):
        for j in range(BOARD_COLS):
            if board[i][j]==0:
                board[i][j]=2
                score = minimax(board,0,False)
                board[i][j]=0
                if score>best_score:
                    best_score=score
                    move = (i,j)
    if move:
        board[move[0]][move[1]]=2

# Restart game
def restart_game():
    global board
    board = [[0 for _ in range(BOARD_COLS)] for _ in range(BOARD_ROWS)]

# Draw scores and button
def draw_score_and_button():
    pygame.draw.rect(screen, BUTTON_COLOR, (0, HEIGHT-100, WIDTH, 100))
    score_text = font.render(f"Player: {score_player}  AI: {score_ai}", True, TEXT_COLOR)
    screen.blit(score_text, (20, HEIGHT-70))
    button_text = font.render("Restart (Click Here)", True, TEXT_COLOR)
    screen.blit(button_text, (WIDTH-250, HEIGHT-70))

# Main loop
player = 1
game_over = False
draw_lines()
draw_score_and_button()
pygame.display.update()

while True:
    for event in pygame.event.get():
        if event.type==pygame.QUIT:
            pygame.quit()
            sys.exit()
        if event.type==pygame.MOUSEBUTTONDOWN:
            mouseX = event.pos[0]
            mouseY = event.pos[1]
            
            # Restart button
            if HEIGHT-100 <= mouseY <= HEIGHT:
                restart_game()
                game_over=False
                draw_lines()
                draw_score_and_button()
                draw_figures()
                pygame.display.update()
                continue

            if not game_over and mouseY<HEIGHT-100:
                clicked_row = int(mouseY // SQUARE_SIZE)
                clicked_col = int(mouseX // SQUARE_SIZE)
                if board[clicked_row][clicked_col]==0:
                    board[clicked_row][clicked_col]=1
                    if check_win(1):
                        game_over=True
                        score_player+=1
                    elif board_full():
                        game_over=True
                    else:
                        ai_move()
                        if check_win(2):
                            game_over=True
                            score_ai+=1
                draw_figures()
                draw_score_and_button()
                pygame.display.update()





# import pygame
# import sys

# # Initialize Pygame
# pygame.init()

# # Constants
# WIDTH, HEIGHT = 600, 700
# LINE_WIDTH = 15
# BOARD_ROWS = 3
# BOARD_COLS = 3
# SQUARE_SIZE = WIDTH // BOARD_COLS
# CIRCLE_RADIUS = SQUARE_SIZE//3
# CIRCLE_WIDTH = 15
# CROSS_WIDTH = 25
# SPACE = SQUARE_SIZE//4

# # Colors
# BG_COLOR = (28, 170, 156)
# LINE_COLOR = (23, 145, 135)
# CIRCLE_COLOR = (239, 231, 200)
# CROSS_COLOR = (66, 66, 66)
# TEXT_COLOR = (255, 255, 255)
# BUTTON_COLOR = (50, 50, 50)

# # Screen
# screen = pygame.display.set_mode((WIDTH, HEIGHT))
# pygame.display.set_caption("X and O Game")
# screen.fill(BG_COLOR)

# # Fonts
# font = pygame.font.SysFont(None, 40)

# # Board
# board = [[0 for _ in range(BOARD_COLS)] for _ in range(BOARD_ROWS)]
# score_player1 = 0
# score_player2 = 0

# # Draw lines
# def draw_lines():
#     # Horizontal
#     pygame.draw.line(screen, LINE_COLOR, (0, SQUARE_SIZE), (WIDTH, SQUARE_SIZE), LINE_WIDTH)
#     pygame.draw.line(screen, LINE_COLOR, (0, 2*SQUARE_SIZE), (WIDTH, 2*SQUARE_SIZE), LINE_WIDTH)
#     # Vertical
#     pygame.draw.line(screen, LINE_COLOR, (SQUARE_SIZE,0), (SQUARE_SIZE, HEIGHT-100), LINE_WIDTH)
#     pygame.draw.line(screen, LINE_COLOR, (2*SQUARE_SIZE,0), (2*SQUARE_SIZE, HEIGHT-100), LINE_WIDTH)

# # Draw figures
# def draw_figures():
#     for row in range(BOARD_ROWS):
#         for col in range(BOARD_COLS):
#             if board[row][col] == 1:
#                 pygame.draw.circle(screen, CIRCLE_COLOR, (int(col*SQUARE_SIZE+SQUARE_SIZE/2), int(row*SQUARE_SIZE+SQUARE_SIZE/2)), CIRCLE_RADIUS, CIRCLE_WIDTH)
#             elif board[row][col] == 2:
#                 pygame.draw.line(screen, CROSS_COLOR, (col*SQUARE_SIZE+SPACE, row*SQUARE_SIZE+SQUARE_SIZE-SPACE), 
#                                  (col*SQUARE_SIZE+SQUARE_SIZE-SPACE, row*SQUARE_SIZE+SPACE), CROSS_WIDTH)
#                 pygame.draw.line(screen, CROSS_COLOR, (col*SQUARE_SIZE+SPACE, row*SQUARE_SIZE+SPACE), 
#                                  (col*SQUARE_SIZE+SQUARE_SIZE-SPACE, row*SQUARE_SIZE+SQUARE_SIZE-SPACE), CROSS_WIDTH)

# # Check win
# def check_win(player):
#     for col in range(BOARD_COLS):
#         if board[0][col]==board[1][col]==board[2][col]==player:
#             return True
#     for row in range(BOARD_ROWS):
#         if board[row][0]==board[row][1]==board[row][2]==player:
#             return True
#     if board[0][0]==board[1][1]==board[2][2]==player:
#         return True
#     if board[0][2]==board[1][1]==board[2][0]==player:
#         return True
#     return False

# def board_full():
#     for row in range(BOARD_ROWS):
#         for col in range(BOARD_COLS):
#             if board[row][col]==0:
#                 return False
#     return True

# # Restart game
# def restart_game():
#     global board
#     board = [[0 for _ in range(BOARD_COLS)] for _ in range(BOARD_ROWS)]

# # Draw scores and button
# def draw_score_and_button():
#     pygame.draw.rect(screen, BUTTON_COLOR, (0, HEIGHT-100, WIDTH, 100))
#     score_text = font.render(f"Player O: {score_player1}  Player X: {score_player2}", True, TEXT_COLOR)
#     screen.blit(score_text, (20, HEIGHT-70))
#     button_text = font.render("Restart (Click Here)", True, TEXT_COLOR)
#     screen.blit(button_text, (WIDTH-250, HEIGHT-70))

# # Main loop
# player = 1  # Player 1 = O (circle), Player 2 = X (cross)
# game_over = False
# draw_lines()
# draw_score_and_button()
# pygame.display.update()

# while True:
#     for event in pygame.event.get():
#         if event.type==pygame.QUIT:
#             pygame.quit()
#             sys.exit()
#         if event.type==pygame.MOUSEBUTTONDOWN:
#             mouseX = event.pos[0]
#             mouseY = event.pos[1]
            
#             # Restart button
#             if HEIGHT-100 <= mouseY <= HEIGHT:
#                 restart_game()
#                 game_over=False
#                 draw_lines()
#                 draw_score_and_button()
#                 draw_figures()
#                 pygame.display.update()
#                 continue

#             if not game_over and mouseY<HEIGHT-100:
#                 clicked_row = int(mouseY // SQUARE_SIZE)
#                 clicked_col = int(mouseX // SQUARE_SIZE)
#                 if board[clicked_row][clicked_col]==0:
#                     board[clicked_row][clicked_col]=player
#                     if check_win(player):
#                         game_over=True
#                         if player==1: score_player1+=1
#                         else: score_player2+=1
#                     elif board_full():
#                         game_over=True
#                     player = 2 if player==1 else 1
#                 draw_figures()
#                 draw_score_and_button()
#                 pygame.display.update()





# import pygame
# import sys

# # Initialize Pygame and mixer for sound
# pygame.init()
# pygame.mixer.init()

# # Load sounds
# click_sound = pygame.mixer.Sound("click.wav")
# win_sound = pygame.mixer.Sound("win.wav")

# # Constants
# WIDTH, HEIGHT = 600, 700
# LINE_WIDTH = 15
# BOARD_ROWS = 3
# BOARD_COLS = 3
# SQUARE_SIZE = WIDTH // BOARD_COLS
# CIRCLE_RADIUS = SQUARE_SIZE//3
# CIRCLE_WIDTH = 15
# CROSS_WIDTH = 25
# SPACE = SQUARE_SIZE//4

# # Colors
# BG_COLOR = (28, 170, 156)
# LINE_COLOR = (23, 145, 135)
# CIRCLE_COLOR = (239, 231, 200)
# CROSS_COLOR = (66, 66, 66)
# TEXT_COLOR = (255, 255, 255)
# BUTTON_COLOR = (50, 50, 50)
# WIN_LINE_COLOR = (255, 0, 0)

# # Screen
# screen = pygame.display.set_mode((WIDTH, HEIGHT))
# pygame.display.set_caption("X and O Ultimate")
# screen.fill(BG_COLOR)

# # Fonts
# font = pygame.font.SysFont(None, 40)

# # Board
# board = [[0 for _ in range(BOARD_COLS)] for _ in range(BOARD_ROWS)]
# score_player1 = 0
# score_player2 = 0

# # Draw lines
# def draw_lines():
#     pygame.draw.line(screen, LINE_COLOR, (0, SQUARE_SIZE), (WIDTH, SQUARE_SIZE), LINE_WIDTH)
#     pygame.draw.line(screen, LINE_COLOR, (0, 2*SQUARE_SIZE), (WIDTH, 2*SQUARE_SIZE), LINE_WIDTH)
#     pygame.draw.line(screen, LINE_COLOR, (SQUARE_SIZE,0), (SQUARE_SIZE, HEIGHT-100), LINE_WIDTH)
#     pygame.draw.line(screen, LINE_COLOR, (2*SQUARE_SIZE,0), (2*SQUARE_SIZE, HEIGHT-100), LINE_WIDTH)

# # Draw figures
# def draw_figures():
#     for row in range(BOARD_ROWS):
#         for col in range(BOARD_COLS):
#             if board[row][col] == 1:
#                 pygame.draw.circle(screen, CIRCLE_COLOR, (int(col*SQUARE_SIZE+SQUARE_SIZE/2), int(row*SQUARE_SIZE+SQUARE_SIZE/2)), CIRCLE_RADIUS, CIRCLE_WIDTH)
#             elif board[row][col] == 2:
#                 pygame.draw.line(screen, CROSS_COLOR, (col*SQUARE_SIZE+SPACE, row*SQUARE_SIZE+SQUARE_SIZE-SPACE), 
#                                  (col*SQUARE_SIZE+SQUARE_SIZE-SPACE, row*SQUARE_SIZE+SPACE), CROSS_WIDTH)
#                 pygame.draw.line(screen, CROSS_COLOR, (col*SQUARE_SIZE+SPACE, row*SQUARE_SIZE+SPACE), 
#                                  (col*SQUARE_SIZE+SQUARE_SIZE-SPACE, row*SQUARE_SIZE+SQUARE_SIZE-SPACE), CROSS_WIDTH)

# # Check win
# def check_win(player):
#     # Rows
#     for row in range(BOARD_ROWS):
#         if board[row][0]==board[row][1]==board[row][2]==player:
#             return ('row', row)
#     # Columns
#     for col in range(BOARD_COLS):
#         if board[0][col]==board[1][col]==board[2][col]==player:
#             return ('col', col)
#     # Diagonals
#     if board[0][0]==board[1][1]==board[2][2]==player:
#         return ('diag', 1)
#     if board[0][2]==board[1][1]==board[2][0]==player:
#         return ('diag', 2)
#     return None

# def draw_win_line(win):
#     if win[0]=='row':
#         y = win[1]*SQUARE_SIZE + SQUARE_SIZE//2
#         pygame.draw.line(screen, WIN_LINE_COLOR, (15, y), (WIDTH-15, y), 15)
#     elif win[0]=='col':
#         x = win[1]*SQUARE_SIZE + SQUARE_SIZE//2
#         pygame.draw.line(screen, WIN_LINE_COLOR, (x, 15), (x, HEIGHT-115), 15)
#     elif win[0]=='diag':
#         if win[1]==1:
#             pygame.draw.line(screen, WIN_LINE_COLOR, (15, 15), (WIDTH-15, HEIGHT-115), 15)
#         else:
#             pygame.draw.line(screen, WIN_LINE_COLOR, (WIDTH-15, 15), (15, HEIGHT-115), 15)

# def board_full():
#     for row in range(BOARD_ROWS):
#         for col in range(BOARD_COLS):
#             if board[row][col]==0:
#                 return False
#     return True

# # Restart game
# def restart_game():
#     global board
#     board = [[0 for _ in range(BOARD_COLS)] for _ in range(BOARD_ROWS)]

# # Draw scores and button
# def draw_score_and_button():
#     pygame.draw.rect(screen, BUTTON_COLOR, (0, HEIGHT-100, WIDTH, 100))
#     score_text = font.render(f"Player O: {score_player1}  Player X: {score_player2}", True, TEXT_COLOR)
#     screen.blit(score_text, (20, HEIGHT-70))
#     button_text = font.render("Restart (Click Here)", True, TEXT_COLOR)
#     screen.blit(button_text, (WIDTH-250, HEIGHT-70))

# # MiniMax AI
# def minimax(board_state, depth, is_ai):
#     if check_win(2): return 10 - depth
#     if check_win(1): return depth - 10
#     if board_full(): return 0
#     if is_ai:
#         best=-1000
#         for i in range(3):
#             for j in range(3):
#                 if board_state[i][j]==0:
#                     board_state[i][j]=2
#                     score = minimax(board_state, depth+1, False)
#                     board_state[i][j]=0
#                     best=max(best,score)
#         return best
#     else:
#         best=1000
#         for i in range(3):
#             for j in range(3):
#                 if board_state[i][j]==0:
#                     board_state[i][j]=1
#                     score = minimax(board_state, depth+1, True)
#                     board_state[i][j]=0
#                     best=min(best,score)
#         return best

# def ai_move():
#     best_score=-1000
#     move=None
#     for i in range(3):
#         for j in range(3):
#             if board[i][j]==0:
#                 board[i][j]=2
#                 score=minimax(board,0,False)
#                 board[i][j]=0
#                 if score>best_score:
#                     best_score=score
#                     move=(i,j)
#     if move:
#         board[move[0]][move[1]]=2
#         click_sound.play()

# # Main loop
# player = 1  # Player 1 = O, Player 2 = X or AI
# game_over = False
# ai_mode = True  # True = play vs AI, False = 2-player local
# draw_lines()
# draw_score_and_button()
# pygame.display.update()

# while True:
#     for event in pygame.event.get():
#         if event.type==pygame.QUIT:
#             pygame.quit()
#             sys.exit()
#         if event.type==pygame.MOUSEBUTTONDOWN:
#             mouseX = event.pos[0]
#             mouseY = event.pos[1]
            
#             # Restart button
#             if HEIGHT-100 <= mouseY <= HEIGHT:
#                 restart_game()
#                 game_over=False
#                 draw_lines()
#                 draw_score_and_button()
#                 draw_figures()
#                 pygame.display.update()
#                 continue

#             if not game_over and mouseY<HEIGHT-100:
#                 clicked_row = int(mouseY // SQUARE_SIZE)
#                 clicked_col = int(mouseX // SQUARE_SIZE)
#                 if board[clicked_row][clicked_col]==0:
#                     board[clicked_row][clicked_col]=player
#                     click_sound.play()
#                     win = check_win(player)
#                     if win:
#                         draw_win_line(win)
#                         pygame.display.update()
#                         win_sound.play()
#                         if player==1: score_player1+=1
#                         else: score_player2+=1
#                         game_over=True
#                     elif board_full():
#                         game_over=True
#                     player = 2 if player==1 else 1

#                     draw_figures()
#                     draw_score_and_button()
#                     pygame.display.update()

#                     # AI move
#                     if ai_mode and not game_over and player==2:
#                         ai_move()
#                         win = check_win(2)
#                         if win:
#                             draw_win_line(win)
#                             pygame.display.update()
#                             win_sound.play()
#                             score_player2+=1
#                             game_over=True
#                         elif board_full():
#                             game_over=True
#                         player=1
#                         draw_figures()
#                         draw_score_and_button()
#                         pygame.display.update()





# import pygame
# import sys

# # Initialize Pygame and mixer for sound
# pygame.init()
# pygame.mixer.init()

# # Load sounds
# click_sound = pygame.mixer.Sound("click.wav")
# win_sound = pygame.mixer.Sound("win.wav")

# # Constants
# WIDTH, HEIGHT = 600, 700
# LINE_WIDTH = 15
# BOARD_ROWS = 3
# BOARD_COLS = 3
# SQUARE_SIZE = WIDTH // BOARD_COLS
# CIRCLE_RADIUS = SQUARE_SIZE//3
# CIRCLE_WIDTH = 15
# CROSS_WIDTH = 25
# SPACE = SQUARE_SIZE//4

# # Colors
# BG_COLOR = (28, 170, 156)
# LINE_COLOR = (23, 145, 135)
# CIRCLE_COLOR = (239, 231, 200)
# CROSS_COLOR = (66, 66, 66)
# TEXT_COLOR = (255, 255, 255)
# BUTTON_COLOR = (50, 50, 50)
# WIN_LINE_COLOR = (255, 0, 0)
# MENU_BG_COLOR = (40, 40, 40)
# MENU_BTN_COLOR = (100, 100, 100)

# # Screen
# screen = pygame.display.set_mode((WIDTH, HEIGHT))
# pygame.display.set_caption("X and O Ultimate")
# screen.fill(BG_COLOR)

# # Fonts
# font = pygame.font.SysFont(None, 40)
# menu_font = pygame.font.SysFont(None, 60)

# # Board
# board = [[0 for _ in range(BOARD_COLS)] for _ in range(BOARD_ROWS)]
# score_player1 = 0
# score_player2 = 0

# # Game Mode
# game_mode = None  # None = menu, 'AI' = vs AI, '2P' = two players

# # Draw menu
# def draw_menu():
#     screen.fill(MENU_BG_COLOR)
#     title = menu_font.render("X and O Game", True, TEXT_COLOR)
#     screen.blit(title, (WIDTH//2 - title.get_width()//2, 100))
#     ai_btn = pygame.Rect(WIDTH//2 - 150, 250, 300, 80)
#     p2_btn = pygame.Rect(WIDTH//2 - 150, 400, 300, 80)
#     pygame.draw.rect(screen, MENU_BTN_COLOR, ai_btn)
#     pygame.draw.rect(screen, MENU_BTN_COLOR, p2_btn)
#     ai_text = font.render("Single Player (AI)", True, TEXT_COLOR)
#     p2_text = font.render("Two Players", True, TEXT_COLOR)
#     screen.blit(ai_text, (WIDTH//2 - ai_text.get_width()//2, 275))
#     screen.blit(p2_text, (WIDTH//2 - p2_text.get_width()//2, 425))
#     pygame.display.update()
#     return ai_btn, p2_btn

# # Draw lines
# def draw_lines():
#     pygame.draw.line(screen, LINE_COLOR, (0, SQUARE_SIZE), (WIDTH, SQUARE_SIZE), LINE_WIDTH)
#     pygame.draw.line(screen, LINE_COLOR, (0, 2*SQUARE_SIZE), (WIDTH, 2*SQUARE_SIZE), LINE_WIDTH)
#     pygame.draw.line(screen, LINE_COLOR, (SQUARE_SIZE,0), (SQUARE_SIZE, HEIGHT-100), LINE_WIDTH)
#     pygame.draw.line(screen, LINE_COLOR, (2*SQUARE_SIZE,0), (2*SQUARE_WIDTH, HEIGHT-100), LINE_WIDTH)

# # Draw figures
# def draw_figures():
#     for row in range(BOARD_ROWS):
#         for col in range(BOARD_COLS):
#             if board[row][col] == 1:
#                 pygame.draw.circle(screen, CIRCLE_COLOR, (int(col*SQUARE_SIZE+SQUARE_SIZE/2), int(row*SQUARE_SIZE+SQUARE_SIZE/2)), CIRCLE_RADIUS, CIRCLE_WIDTH)
#             elif board[row][col] == 2:
#                 pygame.draw.line(screen, CROSS_COLOR, (col*SQUARE_SIZE+SPACE, row*SQUARE_SIZE+SQUARE_SIZE-SPACE), 
#                                  (col*SQUARE_SIZE+SQUARE_SIZE-SPACE, row*SQUARE_SIZE+SPACE), CROSS_WIDTH)
#                 pygame.draw.line(screen, CROSS_COLOR, (col*SQUARE_SIZE+SPACE, row*SQUARE_SIZE+SPACE), 
#                                  (col*SQUARE_SIZE+SQUARE_SIZE-SPACE, row*SQUARE_SIZE+SQUARE_SIZE-SPACE), CROSS_WIDTH)

# # Check win
# def check_win(player):
#     for row in range(BOARD_ROWS):
#         if board[row][0]==board[row][1]==board[row][2]==player:
#             return ('row', row)
#     for col in range(BOARD_COLS):
#         if board[0][col]==board[1][col]==board[2][col]==player:
#             return ('col', col)
#     if board[0][0]==board[1][1]==board[2][2]==player:
#         return ('diag', 1)
#     if board[0][2]==board[1][1]==board[2][0]==player:
#         return ('diag', 2)
#     return None

# def draw_win_line(win):
#     if win[0]=='row':
#         y = win[1]*SQUARE_SIZE + SQUARE_SIZE//2
#         pygame.draw.line(screen, WIN_LINE_COLOR, (15, y), (WIDTH-15, y), 15)
#     elif win[0]=='col':
#         x = win[1]*SQUARE_SIZE + SQUARE_SIZE//2
#         pygame.draw.line(screen, WIN_LINE_COLOR, (x, 15), (x, HEIGHT-115), 15)
#     elif win[0]=='diag':
#         if win[1]==1:
#             pygame.draw.line(screen, WIN_LINE_COLOR, (15, 15), (WIDTH-15, HEIGHT-115), 15)
#         else:
#             pygame.draw.line(screen, WIN_LINE_COLOR, (WIDTH-15, 15), (15, HEIGHT-115), 15)

# def board_full():
#     for row in range(BOARD_ROWS):
#         for col in range(BOARD_COLS):
#             if board[row][col]==0:
#                 return False
#     return True

# def restart_game():
#     global board
#     board = [[0 for _ in range(BOARD_COLS)] for _ in range(BOARD_ROWS)]

# def draw_score_and_button():
#     pygame.draw.rect(screen, BUTTON_COLOR, (0, HEIGHT-100, WIDTH, 100))
#     score_text = font.render(f"Player O: {score_player1}  Player X: {score_player2}", True, TEXT_COLOR)
#     screen.blit(score_text, (20, HEIGHT-70))
#     button_text = font.render("Restart (Click Here)", True, TEXT_COLOR)
#     screen.blit(button_text, (WIDTH-250, HEIGHT-70))

# # MiniMax AI
# def minimax(board_state, depth, is_ai):
#     if check_win(2): return 10 - depth
#     if check_win(1): return depth - 10
#     if board_full(): return 0
#     if is_ai:
#         best=-1000
#         for i in range(3):
#             for j in range(3):
#                 if board_state[i][j]==0:
#                     board_state[i][j]=2
#                     score = minimax(board_state, depth+1, False)
#                     board_state[i][j]=0
#                     best=max(best,score)
#         return best
#     else:
#         best=1000
#         for i in range(3):
#             for j in range(3):
#                 if board_state[i][j]==0:
#                     board_state[i][j]=1
#                     score = minimax(board_state, depth+1, True)
#                     board_state[i][j]=0
#                     best=min(best,score)
#         return best

# def ai_move():
#     best_score=-1000
#     move=None
#     for i in range(3):
#         for j in range(3):
#             if board[i][j]==0:
#                 board[i][j]=2
#                 score=minimax(board,0,False)
#                 board[i][j]=0
#                 if score>best_score:
#                     best_score=score
#                     move=(i,j)
#     if move:
#         board[move[0]][move[1]]=2
#         click_sound.play()

# # --- Main Loop ---
# player = 1  # Player 1 = O, Player 2 = X
# game_over = False

# # Show menu first
# ai_btn, p2_btn = draw_menu()

# while True:
#     for event in pygame.event.get():
#         if event.type==pygame.QUIT:
#             pygame.quit()
#             sys.exit()
#         if game_mode is None:
#             if event.type==pygame.MOUSEBUTTONDOWN:
#                 if ai_btn.collidepoint(event.pos):
#                     game_mode = 'AI'
#                     screen.fill(BG_COLOR)
#                     draw_lines()
#                     draw_score_and_button()
#                 elif p2_btn.collidepoint(event.pos):
#                     game_mode = '2P'
#                     screen.fill(BG_COLOR)
#                     draw_lines()
#                     draw_score_and_button()
#         else:
#             if event.type==pygame.MOUSEBUTTONDOWN:
#                 mouseX = event.pos[0]
#                 mouseY = event.pos[1]
                
#                 # Restart button
#                 if HEIGHT-100 <= mouseY <= HEIGHT:
#                     restart_game()
#                     game_over=False
#                     draw_lines()
#                     draw_score_and_button()
#                     draw_figures()
#                     pygame.display.update()
#                     continue

#                 if not game_over and mouseY<HEIGHT-100:
#                     clicked_row = int(mouseY // SQUARE_SIZE)
#                     clicked_col = int(mouseX // SQUARE_SIZE)
#                     if board[clicked_row][clicked_col]==0:
#                         board[clicked_row][clicked_col]=player
#                         click_sound.play()
#                         win = check_win(player)
#                         if win:
#                             draw_win_line(win)
#                             pygame.display.update()
#                             win_sound.play()
#                             if player==1: score_player1+=1
#                             else: score_player2+=1
#                             game_over=True
#                         elif board_full():
#                             game_over=True
#                         player = 2 if player==1 else 1

#                         draw_figures()
#                         draw_score_and_button()
#                         pygame.display.update()

#                         # AI move
#                         if game_mode=='AI' and not game_over and player==2:
#                             ai_move()
#                             win = check_win(2)
#                             if win:
#                                 draw_win_line(win)
#                                 pygame.display.update()
#                                 win_sound.play()
#                                 score_player2+=1
#                                 game_over=True
#                             elif board_full():
#                                 game_over=True
#                             player=1
#                             draw_figures()
#                             draw_score_and_button()
#                             pygame.display.update()
