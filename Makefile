make  : 
	@make all -C Mandatory

bonus : 
	@make all -C bonus

clean:
	@make clean -C Mandatory
	@make clean -C bonus
fclean:
	@make fclean -C Mandatory
	@make fclean -C bonus

re:
	@make re -C Mandatory
	@make re -C bonus

.PHONY:Mandatory make bonus clean fclean re 