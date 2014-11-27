#!/usr/bin/python
# -*- coding: utf-8 -*-

"""
Simple PyQt4 window example
"""

''' Provides necessary imports. Basic GUI widgets are in QtGui module. '''
import sys
from PyQt4 import QtGui


def main():

    '''Every PyQt4 application must createan application object, located in the QtGui module. ''' 
    app = QtGui.QApplication(sys.argv)

    '''The QtGui.QWidget widget is the base class of all user interface objects in PyQt4'''
    w = QtGui.QWidget()
    #w = QtGui.QMainWindow()
    w.resize(400, 300)
    w.move(300, 300)
    w.setWindowTitle('BlackChat by Alpaca Security Solutions')
    w.show()

    sys.exit(app.exec_())

if __name__ == '__main__':
    main()