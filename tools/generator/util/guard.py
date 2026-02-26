class ScopeGuard:
    def __init__(self, writer, scope):
        self.writer = writer
        self.scope = scope

    def __enter__(self):
        if self.scope.ifdef:
            self.writer.ifdef(self.scope.ifdef)

        if self.scope.ifndef:
            self.writer.ifndef(self.scope.ifndef)
        
    def __exit__(self, exc_type, exc_value, traceback):
        if self.scope.ifdef:
            self.writer.endif()

        if self.scope.ifndef:
            self.writer.endif()

        self.writer.newline()
