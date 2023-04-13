#ifndef BSM_H
#define BSM_H

#include <string>
#include <vector>
using namespace std;

class BSM {
private:
    struct CoreData {
        int msgCnt;
        string id;
        int secMark;
        int lat;
        int longitude;
        int elev;
        struct Accuracy {
            int semiMajor;
            int semiMinor;
            int orientation;
        } accuracy;
        string transmission;
        int speed;
        int heading;
        int angle;
        struct AccelSet {
            int longi;
            int lat;
            int vert;
            int yaw;
        } accelSet;
        struct Brakes {
            string wheelBrakes;
            int traction;
            int abs;
            int scs;
            int brakeBoost;
            int auxBrakes;
        } brakes;
        struct Size {
            int width;
            int length;
        } size;
    } coreData;
    struct PartII {
        struct VehicleSafetyExtensions {
            string events;
            struct PathHistory {
                struct InitialPosition {
                    struct UtcTime {
                        int year;
                        int month;
                        int day;
                        int hour;
                        int minute;
                        int second;
                        int offset;
                    } utcTime;
                    int longitude;
                    int latitude;
                    int elevation;
                    int heading;
                    struct Speed {
                        int transmission;
                        int speed;
                    } speed;
                    struct PosAccuracy {
                        int semiMajor;
                        int semiMinor;
                        int orientation;
                    } posAccuracy;
                    int timeConfidence;
                    struct PosConfidence {
                        int pos;
                        int elevation;
                    } posConfidence;
                    struct SpeedConfidence {
                        int heading;
                        int speed;
                        int throttle;
                    } speedConfidence;
                } initialPosition;
                int currGNSSstatus;
                struct CrumbData {
                    int latOffset;
                    int lonOffset;
                    int elevationOffset;
                    int timeOffset;
                    int speed;
                    struct PosAccuracy {
                        int semiMajor;
                        int semiMinor;
                        int orientation;
                    } posAccuracy;
                    int heading;
                } crumbData;
            } pathHistory;
            struct PathPrediction {
                int radiusOfCurve;
                int confidence;
            } pathPrediction;
                string lights;
        } vehicleSafetyExtensions;
        struct SpecialVehicleExtensions {
            struct VehicleAlerts {
                int sspRights;
                string sirenUse;
                int lightsUse;
                int multi;
                struct Events {
                    int sspRights;
                    int event;
                } events;
                string responseType;
            } vehicleAlerts;
            struct Description {
                int typeEvent;
                int description;
                int priority;
                int heading;
                int extent;
            } description;
            struct Trailers {
                int sspRights;
                struct Connection {
                    int pivotOffset;
                    int pivotAngle;
                    bool pivots;
                } connection;
                struct Units {
                    bool isDolly;
                    int width;
                    int length;
                    int height;
                    int mass;
                } units;
            } trailers;
        } specialVehicleExtensions;
    } partII;

public:
    double getLatitude();
    double getLongitude();
};

#endif // BSM_H
