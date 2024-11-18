cases = int(input())

for i in range(cases):
    riverLength, jumpDist, swimDist = input().split()

    riverLength = int(riverLength)
    jumpDist = int(jumpDist)
    swimDist = int(swimDist)

    river = input()
    river += "L"
    position = -1

    while position < riverLength:
        print(position)
        nearestLogPosition = river.find("L",position+1, position+jumpDist+1)
        print("nearest log position: ", nearestLogPosition)
        
        if nearestLogPosition != -1:
            position = nearestLogPosition
        elif nearestLogPosition == -1:
            # nearestWaterPosition = river.find("W",position+1, position+jumpDist+1)
            farthestWaterPosition = -1
            for j in range(position+jumpDist, position, -1):
                if river[j] == 'W':
                    farthestWaterPosition = j
                    break

            if farthestWaterPosition == -1:
                break
            elif farthestWaterPosition != -1:
                position = farthestWaterPosition
            
            print("swim dist: ", swimDist)
            if swimDist == 0:
                break
            elif swimDist > 0:
                nearestLogPosition = river.find("L", position+1, position+swimDist+2)
                nearestCrocodilePosition = river.find("C", position+1, position+swimDist+2)
                print("nearest log position: ", nearestLogPosition)
                print("nearest crocodile position: ", nearestCrocodilePosition)

                if nearestLogPosition == -1:
                    break
                elif nearestLogPosition != -1:
                    if nearestCrocodilePosition == -1:
                        swimDist -= ((nearestLogPosition - position) - 1)
                        position = nearestLogPosition
                    elif nearestCrocodilePosition != -1:
                        if nearestLogPosition > nearestCrocodilePosition:
                            break
                        elif nearestLogPosition < nearestCrocodilePosition:
                            swimDist -= ((nearestLogPosition - position) - 1)
                            position = nearestLogPosition
    
    if position == riverLength:
        print("YES")
    elif position != riverLength:
        print("NO")