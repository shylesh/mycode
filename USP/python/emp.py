#!/bin/python

class Employee:
	def __init__ (self, name, sal=0):
		self.name = name
		self.sal = sal
	def give_rise (self, inc):
		self.sal = self.sal + self.sal * inc
	def work (self):
		print self.name, 'does stuff'
	def __repr__ (self):
		return "<emp: name=%s, sal=%s>" % (self.name, self.sal)

class chef(Employee):
	def __init__ (self, name):
		Employee.__init__(self, name, 5000)
	def work (self):
		print self.name, "makes food"

class server(Employee):
	def __init__ (self, name):
		Employee.__init__(self, name, 1000)
	def work(self):
		print self.name, "server"

class pizza_robot(chef):
	def __init__ (self, name):
		chef.__init__( self, name)
	def work(self):
		print self.name, "makes pizza"


if __name__ == "__main__":
	bob = pizza_robot('bob')
	print bob

	bob.give_rise (10)
	print bob
	print
	for k in Employee, chef, server, pizza_robot:
		obj = k(k.__name__)
		obj.work()


