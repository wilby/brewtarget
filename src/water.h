/*
 * water.h is part of Brewtarget, and is Copyright Philip G. Lee
 * (rocketman768@gmail.com), 2009-2011.
 *
 * Brewtarget is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * Brewtarget is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _WATER_H
#define   _WATER_H

#include <QDomNode>
#include <QString>
#include "BeerXMLElement.h"

// Forward declarations.
class Water;
bool operator<(Water &w1, Water &w2);
bool operator==(Water &w1, Water &w2);

class Water : public BeerXMLElement
{
   Q_OBJECT
   
   friend class Database;
public:

   virtual ~Water() {}
   
   Q_PROPERTY( QString name READ name WRITE setName /*NOTIFY changed*/ /*changedName*/ );
   Q_PROPERTY( double amount_l READ amount_l WRITE setAmount_l /*NOTIFY changed*/ /*changedAmount_l*/ );
   Q_PROPERTY( double calcium_ppm READ calcium_ppm WRITE setCalcium_ppm /*NOTIFY changed*/ /*changedCalcium_ppm*/ );
   Q_PROPERTY( double bicarbonate_ppm READ bicarbonate_ppm WRITE setBicarbonate_ppm /*NOTIFY changed*/ /*changedBicarbonate_ppm*/ );
   Q_PROPERTY( double sulfate_ppm READ sulfate_ppm WRITE setSulfate_ppm /*NOTIFY changed*/ /*changedSulfate_ppm*/ );
   Q_PROPERTY( double chloride_ppm READ chloride_ppm WRITE setChloride_ppm /*NOTIFY changed*/ /*changedChloride_ppm*/ );
   Q_PROPERTY( double sodium_ppm READ sodium_ppm WRITE setSodium_ppm /*NOTIFY changed*/ /*changedSodium_ppm*/ );
   Q_PROPERTY( double magnesium_ppm READ magnesium_ppm WRITE setMagnesium_ppm /*NOTIFY changed*/ /*changedMagnesium_ppm*/ );
   Q_PROPERTY( double ph READ ph WRITE setPh /*NOTIFY changed*/ /*changedPh*/ );
   Q_PROPERTY( QString notes READ notes WRITE setNotes /*NOTIFY changed*/ /*changedNotes*/ );
   
   QString name() const;
   double amount_l() const;
   double calcium_ppm() const;
   double bicarbonate_ppm() const;
   double sulfate_ppm() const;
   double chloride_ppm() const;
   double sodium_ppm() const;
   double magnesium_ppm() const;
   double ph() const;
   QString notes() const;

   void setName( const QString &var );
   void setAmount_l( double var );
   void setCalcium_ppm( double var );
   void setSulfate_ppm( double var );
   void setBicarbonate_ppm( double var );
   void setChloride_ppm( double var );
   void setSodium_ppm( double var );
   void setMagnesium_ppm( double var );
   void setPh( double var );
   void setNotes( const QString &var );
   
signals:
   /*
   void changedName(QString);
   void changedAmount_l(double);
   void changedCalcium_ppm(double);
   void changedBicarbonate_ppm(double);
   void changedSulfate_ppm(double);
   void changedChloride_ppm(double);
   void changedSodium_ppm(double);
   void changedMagnesium_ppm(double);
   void changedPh(double);
   void changedNotes(QString);
   */
   
private:
   Water();
   Water( Water const& other );
   
   static QHash<QString,QString> tagToProp;
   static QHash<QString,QString> tagToPropHash();
};

inline bool WaterPtrLt( Water* lhs, Water* rhs)
{
   return *lhs < *rhs;
}

inline bool WaterPtrEq( Water* lhs, Water* rhs)
{
   return *lhs == *rhs;
}

struct Water_ptr_cmp
{
   bool operator()( Water* lhs, Water* rhs)
   {
      return *lhs < *rhs;
   }
};

struct Water_ptr_equals
{
   bool operator()( Water* lhs, Water* rhs )
   {
      return *lhs == *rhs;
   }
};

#endif   /* _WATER_H */

