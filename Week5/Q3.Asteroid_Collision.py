class Solution:
    def asteroidCollision(self, asteroids):
        stack = []
        
        for new in asteroids:
            while stack and 0 < stack[-1] and new < 0 :
                if stack[-1] < -new:
                    stack.pop()
                    continue
                elif stack[-1] == -new:
                    stack.pop()
                break
            else:
                stack.append(new)
                
        return stack


    def asteroidCollision2(self, asteroids):
        changed = False
        for i in range(len(asteroids)-1):
            if asteroids[i] > 0 and asteroids[i+1] < 0:
                changed = True
                if asteroids[i] > -asteroids[i+1]:
                    asteroids[i+1] = 0
                elif asteroids[i] == -asteroids[i+1]:
                    asteroids[i] = 0
                    asteroids[i+1] = 0
                else:
                    asteroids[i] = 0

        if not changed:
            return asteroids

        return self.asteroidCollision2([val for val in asteroids if val])


    def asteroidCollision3(self, asteroids):
        stack = []
        for number in asteroids:
            stack.append(number)
            while len(stack)>1 and stack[-1] < 0 and stack[-2] > 0:
                last = stack.pop()
                if -last > stack[-1]:
                    stack[-1] = last
                elif -last == stack[-1]:
                    stack.pop()
        
        return stack


