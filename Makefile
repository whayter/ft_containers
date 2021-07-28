NAME = ft_containers

VCT_DIR = ./vector
STK_DIR = ./stack
MAP_DIR = ./map
OUT_DIR = ./out

RM = rm -rf

STRT_STYLE = \033[0;34m
END_STYLE = \033[0m

all: vector stack map

vector:
	@(make -C $(VCT_DIR) --no-print-directory)
	@(echo "$(STRT_STYLE)Testing vector...$(END_STYLE)")
	@-(make test -C $(VCT_DIR) --no-print-directory)
	@(echo "$(STRT_STYLE)Done. $(END_STYLE)")

stack:
	@(make -C $(STK_DIR) --no-print-directory)
	@(echo "$(STRT_STYLE)Testing stack...$(END_STYLE)")
	@-(make test -C $(STK_DIR) --no-print-directory)
	@(echo "$(STRT_STYLE)Done.$(END_STYLE)")

map:
	@(make -C $(MAP_DIR) --no-print-directory)
	@(echo "$(STRT_STYLE)Testing map...$(END_STYLE)")
	@-(make test -C $(MAP_DIR) --no-print-directory)
	@(echo "$(STRT_STYLE)Done.$(END_STYLE)")

clean:
	@(echo "$(STRT_STYLE)Cleaning...$(END_STYLE)")
	@(make clean -C $(VCT_DIR) --no-print-directory)
	@(make clean -C $(STK_DIR) --no-print-directory)
	@(make clean -C $(MAP_DIR) --no-print-directory)
	@($(RM) $(OUT_DIR))
	@(echo "$(STRT_STYLE)Done.$(END_STYLE)")

fclean: clean
	@(echo "$(STRT_STYLE)Fcleaning...$(END_STYLE)")
	@(make fclean -C $(VCT_DIR) --no-print-directory)
	@(make fclean -C $(STK_DIR) --no-print-directory)
	@(make fclean -C $(MAP_DIR) --no-print-directory)
	@($(RM) $(NAME))
	@(echo "$(STRT_STYLE)Done.$(END_STYLE)")

re: fclean all

.PHONY: all clean fclean re map vector stack