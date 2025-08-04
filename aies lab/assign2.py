import random

def randomSolution(tsp):
    """
    Create a random route (permutation of cities).
    """
    cities = list(range(len(tsp)))
    solution = []
    # Randomly select cities to build a route
    for _ in range(len(tsp)):
        randomCity = cities[random.randint(0, len(cities) - 1)]
        solution.append(randomCity)
        cities.remove(randomCity)
    return solution

def routeLength(tsp, solution):
    """
    Calculate total length of the route.
    Assumes the route is a closed loop (returns to start).
    """
    total = 0
    for i in range(len(solution)):
        from_city = solution[i - 1]
        to_city = solution[i]
        total += tsp[from_city][to_city]
    return total

def getNeighbours(solution):
    """
    Generate all neighbors by swapping every pair of cities in the route.
    """
    neighbours = []
    n = len(solution)
    for i in range(n):
        for j in range(i + 1, n):
            # Copy solution and swap cities at i and j
            neighbour = solution.copy()
            neighbour[i], neighbour[j] = neighbour[j], neighbour[i]
            neighbours.append(neighbour)
            # print(neighbours)
    return neighbours

def getBestNeighbour(tsp, neighbours):
    """
    Among all neighbors, find the one with the shortest route.
    """
    best_neighbour = neighbours[0]
    best_route_length = routeLength(tsp, best_neighbour)
    for neighbour in neighbours:
        current_length = routeLength(tsp, neighbour)
        if current_length < best_route_length:
            best_route_length = current_length
            best_neighbour = neighbour
    return best_neighbour, best_route_length

def hillClimbing(tsp):
    """
    Hill Climbing main procedure.
    Returns the best solution found and its length.
    """
    current_solution = randomSolution(tsp)
    current_length = routeLength(tsp, current_solution)
    neighbours = getNeighbours(current_solution)
    best_neighbour, best_neighbour_length = getBestNeighbour(tsp, neighbours)
    # Repeat as long as a better neighbour exists
    while best_neighbour_length < current_length:
        current_solution = best_neighbour
        current_length = best_neighbour_length
        neighbours = getNeighbours(current_solution)
        best_neighbour, best_neighbour_length = getBestNeighbour(tsp, neighbours)
    return current_solution, current_length

def main():
    tsp = [
        [0, 400, 500, 300],
        [400, 0, 300, 500],
        [500, 300, 0, 400],
        [300, 500, 400, 0]
    ]
    solution, length = hillClimbing(tsp)
    print("Best route found:", solution)
    print("Total length:", length)

if __name__ == "__main__":
    main()
