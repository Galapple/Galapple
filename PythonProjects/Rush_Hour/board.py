ROW_NUM = 7
COL_NUM = 7
TARGET_LOCATION = (3, 7)
class Board:
    """
    Add a class description here.
    Write briefly about the purpose of the class
    """

    def __init__(self):
        self.Matrix = []
        for i in range(ROW_NUM):
            for j in range(COL_NUM):
                self.Matrix.append('-')
        self.cars = list()

    def __str__(self):
        """
        This function is called when a board object is to be printed.
        :return: A string of the current status of the board
        """

    def cell_list(self):
        """ This function returns the coordinates of cells in this board
        :return: list of coordinates
        """
        cellList = list()
        for row in range(ROW_NUM):
            for col in range(COL_NUM):
                cellList.append((row, col))
        cellList.append(TARGET_LOCATION)
        return cellList

    def possible_moves(self):
        """ This function returns the legal moves of all cars in this board
        :return: list of tuples of the form (name,movekey,description) 
                 representing legal moves
        """
        legal_moves = list()
        for car in self.cars():
            if self.__CarOrient == 0 & self.__CarLocation[1] + self.CarLength + 1 == '-':
                legal_moves.append(())


    def target_location(self):
        """
        This function returns the coordinates of the location which is to be filled for victory.
        :return: (row,col) of goal location
        """
        return TARGET_LOCATION

    def add_car(self, car):
        """
        Adds a car to the game.
        :param car: car object of car to add
        :return: True upon success. False if failed
        """
        car_coordinates = car.car_coordinates()
        car_len = car.get_car_length()
        car_bound = self.check_bounds()
        car_space = self.check_if_empty()
        car_name = self.check_name()
        if car_bound & car_space & car_name :
            for cell in car_coordinates:
                curr_row = cell[0]
                curr_col = cell[1]
                self.Matrix[curr_row][curr_col] = car_name
                return True
        else:
            return False

    def move_car(self, name, movekey):
        """
        moves car one step in given direction.
        :param name: name of the car to move
        :param movekey: Key of move in car to activate
        :return: True upon success, False otherwise
        """
        curr_car = name.name_to_car()



    def check_bounds(self, car):
        """ Checks if the car is in the right boundaries
        :param car: car object
        :return: true if boundaries are ok false if not
        """
        car_loc = car.get_car_location()
        car_len = car.get_car_length()
        car_ori = car.get_car_orient()
        if car_ori == 0:
            if car_loc[0] >> ROW_NUM or car_loc[0] << 0:
                return False
            if (car_loc[1]) + car_len >> COL_NUM or car_loc[1] << 0 :
                return False
        if car_ori == 1:
            if (car_loc[0] + car_len) >> ROW_NUM:
                return False
            if car_loc[1] >> COL_NUM:
                return False
        else :
            return True

    def check_name(self, car):
            car_name = car.get_car_name()
            for i in ROW_NUM:
                for j in COL_NUM:
                    if self.Matrix[i, j] == car_name :
                        return False

    def check_if_empty(self, car):
        """check if car can be inserted"""
        car_coord = car.car_coordinates()
        car_len = car.get_car_length()
        for i in car_len - 1:
            if car_coord[i] != '-':
                return False
        return True

    def name_to_car(self, name):
        """return object of the given car name"""
        for car in self.cars:
            car_name = car.get_car_name()
            if car_name == name:
                return car
        return None


