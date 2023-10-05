class Attributes: Attributes // Entity attributes have no categories, they are all defined directly in class Attributes
{
    class GVAR(pylonRotation)
    {
        //--- Mandatory properties
        displayName = CSTRING(PylonRotation); // Name assigned to UI control class Title
        tooltip = CSTRING(PylonRotation_Tooltip); // Tooltip assigned to UI control class Title
        property = "pya_pylonRotation_AttributeUniqueID"; // Unique config property name saved in SQM
        control = "Slider"; // UI control base class displayed in Edit Attributes window, points to Cfg3DEN >> Attributes

        // Expression called when applying the attribute in Eden and at the scenario start
        // The expression is called twice - first for data validation, and second for actual saving
        // Entity is passed as _this, value is passed as _value
        // %s is replaced by attribute config name
        // In MP scenario, the expression is called only on server.
        expression = "_this setVariable ['%s',_value]; _this animateSource ['pylon_rotate_source', linearConversion [0, 1, _value, -pi, pi, true], true]";

        // Expression called when custom property is undefined yet (i.e., when setting the attribute for the first time)
        // Entity (unit, group, marker, comment etc.) is passed as _this
        // Returned value is the default value
        // Used when no value is returned, or when it is of other type than NUMBER, STRING or ARRAY
        // Custom attributes of logic entities (e.g., modules) are saved always, even when they have default value
        defaultValue = "0.5";

        //--- Optional properties
        unique = 0; // When 1, only one entity of the type can have the value in the mission (used for example for variable names or player control)
        validate = "number"; // Validate the value before saving. If the value is not of given type e.g. "number", the default value will be set. Can be "none", "expression", "condition", "number" or "variable"
        condition = "object"; // Condition for attribute to appear (see the table below)
        typeName = "NUMBER"; // Defines data type of saved value, can be STRING, NUMBER or BOOL. Used only when control is "Combo", "Edit" or their variants. This is a scripted feature and has no engine support. See code in (configFile >> "Cfg3DEN" >> "Attributes" >> "Combo" >> "attributeSave")
    };
};
