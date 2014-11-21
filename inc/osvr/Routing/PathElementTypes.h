/** @file
    @brief Header

    @date 2014

    @todo enforce/check CRTP using boost static asserts.

    @author
    Ryan Pavlik
    <ryan@sensics.com>
    <http://sensics.com>
*/

// Copyright 2014 Sensics, Inc.
//
// All rights reserved.
//
// (Final version intended to be licensed under
// the Apache License, Version 2.0)

#ifndef INCLUDED_PathElementTypes_h_GUID_5CC817E5_C7CB_45AE_399D_0B0D39579374
#define INCLUDED_PathElementTypes_h_GUID_5CC817E5_C7CB_45AE_399D_0B0D39579374

// Internal Includes
// - none

// Library/third-party includes
#include <boost/variant/variant.hpp>

// Standard includes
// - none

namespace osvr {
namespace routing {
    /// @brief Namespace for the various element types that may constitute a
    /// node in the path tree.
    namespace elements {
        /// @brief Base, using the CRTP, providing some basic functionality for
        /// path elements.
        template <typename Type> class ElementBase {
          public:
            typedef Type type;
            const char *getTypeName() const;
        };

        /// @brief The element type created when requesting a path that isn't
        /// yet in the tree.
        class NullElement : public ElementBase<NullElement> {};

        /// @brief The element type corresponding to a plugin
        class PluginElement : public ElementBase<PluginElement> {};

        /// @brief The element type corresponding to a device, which implements
        /// 0 or more interfaces
        class DeviceElement : public ElementBase<DeviceElement> {};

        /// @brief The element type corresponding to an interface, which often
        /// may have one or more sensors
        class InterfaceElement : public ElementBase<InterfaceElement> {};

        /// @brief The element type corresponding to a particular sensor of an
        /// interface
        class SensorElement : public ElementBase<SensorElement> {};

        /// @brief The element type serving as a physical association of other
        /// elements.
        class PhysicalAssociationElement
            : public ElementBase<PhysicalAssociationElement> {};

        /// @brief The element type corresponding to a logical grouping.
        class LogicalElement : public ElementBase<LogicalElement> {};
    } // namespace elements

} // namespace client
} // namespace osvr

#endif // INCLUDED_PathElementTypes_h_GUID_5CC817E5_C7CB_45AE_399D_0B0D39579374