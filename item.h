# ifndef ITEM_H
# define ITEM_H

# include <iostream>
# include <string>
# include <memory>
class Player;
class Item{

public:
	virtual void applyEffect(std::unique_ptr<Player> const &player) = 0;
} ;


#endif
