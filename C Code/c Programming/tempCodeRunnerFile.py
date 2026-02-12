import pygame
import sys

# Initialize Pygame
pygame.init()

# Constants
WIDTH, HEIGHT = 600, 600
LINE_WIDTH = 15
BOARD_ROWS = 3
BOARD_COLS = 
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

# Screen
screen = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("X and O Game")
screen.fill(BG_COLOR)

# Board
board = [[0 for _ in range(BOARD_COLS)] for _ in range(BOARD_ROWS)]

# Draw lines
def draw_lines():
    # Horizontal
    pygame.draw.line(screen, LINE_COLOR, (0, SQUARE_SIZE), (WIDTH, SQUARE_SIZE), LINE_WIDTH)
    pygame.draw.line(screen, LINE_COLOR, (0, 2*SQUARE_SIZE), (WIDTH, 2*SQUARE_SIZE), LINE_WIDTH)
    # Vertical
    pygame.draw.line(screen, LINE_COLOR, (SQUARE_SIZE,0), (SQUARE_SIZE, HEIGHT), LINE_WIDTH)
    pygame.draw.line(screen, LINE_COLOR, (2*SQUARE_SIZE,0), (2*SQUARE_SIZE, HEIGHT), LINE_WIDTH)

draw_lines()

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
    # Vertical win
    for col in range(BOARD_COLS):
        if board[0][col]==board[1][col]==board[2][col]==player:
            return True
    # Horizontal win
    for row in range(BOARD_ROWS):
        if board[row][0]==board[row][1]==board[row][2]==player:
            return True
    # Diagonals
    if board[0][0]==board[1][1]==board[2][2]==player:
        return True
    if board[0][2]==board[1][1]==board[2][0]==player:
        return True
    return False

# Main loop
player = 1
game_over = False

while True:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            sys.exit()
        if event.type == pygame.MOUSEBUTTONDOWN and not game_over:
            mouseX = event.pos[0]
            mouseY = event.pos[1]

            clicked_row = int(mouseY // SQUARE_SIZE)
            clicked_col = int(mouseX // SQUARE_SIZE)

            if board[clicked_row][clicked_col] == 0:
                board[clicked_row][clicked_col] = player
                if check_win(player):
                    print(f"Player {player} wins!")
                    game_over = True
                player = 2 if player==1 else 1

                draw_figures()

    pygame.display.update()

