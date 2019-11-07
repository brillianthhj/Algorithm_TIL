class Solution:
    def asteroidCollision(self, asteroids):
        self.stack = []
        
        for new in asteroids:
            while self.stack and 0 < self.stack[-1] and new < 0 :
                if self.stack[-1] < -new:
                    self.stack.pop()
                    continue
                elif self.stack[-1] == -new:
                    self.stack.pop()
                break
            else:
                self.stack.append(new)
                
        return self.stack


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

        return self.asteroidCollision([val for val in asteroids if val])
