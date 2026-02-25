class ScopeGuard:
    def __init__(self, writer, scope):
        self.writer = writer
        self.scope = scope

    def __enter__(self):
        if self.scope.ifdef:
            self.writer.ifdef(self.scope.ifdef)
        
    def __exit__(self, exc_type, exc_value, traceback):
        if self.scope.ifdef:
            self.writer.endif()

        self.writer.newline()
