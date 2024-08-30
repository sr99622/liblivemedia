/*******************************************************************************
* liblivemedia.cpp
*
* copyright 2024 Stephen Rhodes
*
* This library is free software; you can redistribute it and/or modify it under
* the terms of the GNU Lesser General Public License as published by the
* Free Software Foundation; either version 3 of the License, or (at your
* option) any later version. (See <http://www.gnu.org/copyleft/lesser.html>.)
*
* This library is distributed in the hope that it will be useful, but WITHOUT
* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
* FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for
* more details.
*
* You should have received a copy of the GNU Lesser General Public License
* along with this library; if not, write to the Free Software Foundation, Inc.,
* 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA
*
*******************************************************************************/

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/operators.h>
#include <pybind11/functional.h>
#include "ProxyServer.h"

namespace py = pybind11;

namespace liblivemedia
{

PYBIND11_MODULE(liblivemedia, m)
{
    m.doc() = "pybind11 liblivemedia plugin";
    py::class_<ProxyServer>(m, "ProxyServer")
        .def(py::init<>())
        .def("addURI", &ProxyServer::addURI)
        .def("getProxyURI", &ProxyServer::getProxyURI)
        .def("getRootURI", &ProxyServer::getRootURI)
        .def("init", &ProxyServer::init)
        .def("watch", &ProxyServer::watch)
        .def("startLoop", &ProxyServer::startLoop)
        .def("stopLoop", &ProxyServer::stopLoop);

    m.attr("__version__") = "1.0.2";
}


}